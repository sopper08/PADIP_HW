#include <iostream>
#include <assert.h>
#include <math.h>
#include <string>
#include <QImage>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define PI 3.14159265358979323846

Mat qimage_to_mat(QImage &img) {
    assert(img.format()==QImage::Format_Grayscale8);

    Mat mat(img.height(), img.width(), CV_8UC1, (void*)img.bits(), img.bytesPerLine());
    return mat.clone();
}

QImage mat_to_qimage(Mat &mat) {
    assert(mat.channels()==1);

    int width, height;
    width = mat.cols;
    height = mat.rows;

    QImage img(width, height, QImage::Format_RGB32);

    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            int pixel = mat.at<uchar>(i, j);
            img.setPixel(j, i, qRgb(pixel, pixel, pixel));
        }
    }

    return img;
}

Mat to_dft(Mat &mat) {
    Mat padded, complex;
    int rows, cols, m, n;

    rows = mat.rows;
    cols = mat.cols;
    m = getOptimalDFTSize(rows);
    n = getOptimalDFTSize(cols);

    copyMakeBorder(mat, padded, 0, m-rows, 0, n-cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
    merge(planes, 2, complex);
    dft(complex, complex);
    return complex;
}

Mat to_shift(Mat &mat) {
    int rows, cols;
    Mat shifted;

    rows = mat.rows;
    cols = mat.cols;
    shifted.create(2*rows, 2*cols, mat.type());

    Mat m0(shifted, Rect(   0,    0, cols, rows)); mat.copyTo(m0);
    Mat m1(shifted, Rect(cols,    0, cols, rows)); mat.copyTo(m1);
    Mat m2(shifted, Rect(   0, rows, cols, rows)); mat.copyTo(m2);
    Mat m3(shifted, Rect(cols, rows, cols, rows)); mat.copyTo(m3);

    return Mat(shifted, Rect(cols/2, rows/2, cols, rows));

}

Mat homomorphic_filter(int cols, int rows, float gh, float gl, float c, float d0) {
    Mat h;
    Mat plane[2] = { Mat::zeros(rows, cols, CV_32F), Mat::zeros(rows, cols, CV_32F) };
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            float u, v, d_uv, r;

            u = float(j-cols/2);
            v = float(i-rows/2);
            d_uv = sqrt(pow(u, 2)+pow(v, 2));
            r = (gh-gl)*(1.0-exp(-c*(pow(d_uv, 2)/pow(d0, 2))))+gl;
            plane[0].at<float>(i, j) = r;
        }
    }
    merge(plane, 2, h);
    h = to_shift(h);
    return h;
}

Mat motion_blurred_filter(int cols, int rows, float t, float a, float b, bool inverse=false, float threshold=0.0) {
    Mat h;
    Mat plane[] = { Mat::zeros(rows, cols, CV_32F), Mat::zeros(rows, cols, CV_32F) };

    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            float u, v, p;
            float re, im;
            u = float(j-cols/2);
            v = float(i-rows/2);
            p = PI*(a*u+b*v);
            if (p==0) { re = 0; im = 0; }
            else {
                re = t/p*sin(p)*cos(p);
                im = -t/p*sin(p)*sin(p);

                if (inverse) {
                    float l;
                    l = pow(re, 2)+pow(im, 2);
                    if (l<threshold) { re = 0; im = 0; }
                    else { re = re/l; im = -im/l; }
                }
            }
            plane[0].at<float>(i, j) = re;
            plane[1].at<float>(i, j) = im;
        }
    }
    merge(plane, 2, h);
    h = to_shift(h);
    return h;
}

Mat wiener_filter(int cols, int rows, float t, float a, float b, float k) {
    Mat h;
    Mat plane[] = { Mat::zeros(rows, cols, CV_32F), Mat::zeros(rows, cols, CV_32F) };

    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            float u, v, p;
            float re, im, l;
            u = float(j-cols/2);
            v = float(i-rows/2);
            p = PI*(a*u+b*v);
            if (p==0) { re = 0; im = 0; }
            else {
                re = t/p*sin(p)*cos(p);
                im = -t/p*sin(p)*sin(p);
                l = pow(re, 2)+pow(im, 2);
                re = re/(l+k); 
                im = -im/(l+k);
            }
            plane[0].at<float>(i, j) = re;
            plane[1].at<float>(i, j) = im;
        }
    }
    merge(plane, 2, h);
    h = to_shift(h);
    return h;
}

QImage filtering(QImage &img, Mat &filter) {
    int width, height;
    Mat mat, fft_mat, mul_mat, ifft_mat;
    QImage img_out;

    width = img.width();
    height = img.height();
    img_out = QImage(width, height, QImage::Format_Grayscale8);

    mat = qimage_to_mat(img);
    mat.convertTo(mat, CV_32F);
    fft_mat = to_dft(mat);
    Mat plane[2];
    split(fft_mat, plane);

    mulSpectrums(filter, fft_mat, mul_mat, 0);

    idft(mul_mat, ifft_mat, DFT_REAL_OUTPUT);
    normalize(ifft_mat, ifft_mat, 0, 1, NORM_MINMAX, ifft_mat.type());
    ifft_mat.convertTo(ifft_mat, CV_8U, 255);
    ifft_mat = ifft_mat(Rect(0, 0, width, height));
    
    img_out = mat_to_qimage(ifft_mat);

    return img_out;
}

int main(int argc, char *argv[]) {
    string filename, cmd;
    QImage img_out;

    if (argc < 3) {
        cout << "Usage: " << argv[0] << " hf <image> <g_h> <g_l> <c> <d0>" << endl;
        cout << "Usage: " << argv[0] << " mb <image> <t> <a> <b>" << endl;
        cout << "Usage: " << argv[0] << " ib <image> <t> <a> <b> <threshold>" << endl;
        cout << "Usage: " << argv[0] << " wf <image> <t> <a> <b> <k>" << endl;
    }

    cmd = argv[1];

    if (cmd == "hf") {
        if (argc != 7) {
            cout << "Usage: " << argv[0] << " hf <image> <g_h> <g_l> <c> <d0>" << endl;
            return 1;
        }

        float g_h, g_l, c, d0;
        int m, n;
        Mat filter;
        
        filename = argv[2];
        g_h = atof(argv[3]);
        g_l = atof(argv[4]);
        c = atof(argv[5]);
        d0 = atof(argv[6]);

        QImage img(filename.c_str());
        img = img.convertToFormat(QImage::Format_Grayscale8);
        m = getOptimalDFTSize(img.width());
        n = getOptimalDFTSize(img.height());
        filter = homomorphic_filter(m, n, g_h, g_l, c, d0);
        img_out = filtering(img, filter);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + "_" + argv[4] + "_" + argv[5] + "_" + argv[6] + ".jpg";
    }
    else if (cmd == "mb") {
        if (argc != 6) {
            cout << "Usage: " << argv[0] << " mb <image> <t> <a> <b>" << endl;
        }

        float t, a, b;
        int m, n;
        Mat filter;
        
        filename = argv[2];
        t = atof(argv[3]);
        a = atof(argv[4]);
        b = atof(argv[5]);

        QImage img(filename.c_str());
        img = img.convertToFormat(QImage::Format_Grayscale8);
        m = getOptimalDFTSize(img.width());
        n = getOptimalDFTSize(img.height());
        filter = motion_blurred_filter(m, n, t, a, b);
        img_out = filtering(img, filter);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + "_" + argv[4] + "_" + argv[5] + ".jpg";
    }
    else if (cmd == "ib") {
        if (argc != 7) {
            cout << "Usage: " << argv[0] << " ib <image> <t> <a> <b> <threshold>" << endl;
            return 0;
        }

        float t, a, b, threshold;
        int m, n;
        Mat filter;
        
        filename = argv[2];
        t = atof(argv[3]);
        a = atof(argv[4]);
        b = atof(argv[5]);
        threshold = atof(argv[6]);

        QImage img(filename.c_str());
        img = img.convertToFormat(QImage::Format_Grayscale8);
        m = getOptimalDFTSize(img.width());
        n = getOptimalDFTSize(img.height());
        filter = motion_blurred_filter(m, n, t, a, b, true, threshold);
        img_out = filtering(img, filter);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + "_" + argv[4] + "_" + argv[5] + "_" + argv[6] + ".jpg";
    }
    else if (cmd == "wf") {
        if (argc != 7) {
            cout << "Usage: " << argv[0] << " wf <image> <t> <a> <b> <k>" << endl;
            return 0;
        }

        float t, a, b, k;
        int m, n;
        Mat filter;
        
        filename = argv[2];
        t = atof(argv[3]);
        a = atof(argv[4]);
        b = atof(argv[5]);
        k = atof(argv[6]);

        QImage img(filename.c_str());
        img = img.convertToFormat(QImage::Format_Grayscale8);
        m = getOptimalDFTSize(img.width());
        n = getOptimalDFTSize(img.height());
        filter = wiener_filter(m, n, t, a, b, k);
        img_out = filtering(img, filter);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + "_" + argv[4] + "_" + argv[5] + "_" + argv[6] + ".jpg";
    }
    img_out.save(filename.c_str());
    return 0;
}