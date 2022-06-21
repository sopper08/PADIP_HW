#include <iostream>
#include <assert.h>
#include <math.h>
#include <string>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#define PI 3.14159265358979323846

Mat qimage_to_mat(QImage &img) {
    if (img.format()==QImage::Format_Grayscale8) {
        Mat m(img.height(), img.width(), CV_8UC1, const_cast<uchar*>(img.bits()), img.bytesPerLine());
        return m;
    } 
    else if (img.format()==QImage::Format_RGB32) {
        Mat m(img.height(), img.width(), CV_8UC4, const_cast<uchar*>(img.bits()), img.bytesPerLine());
        return m;
    }
    else {
        return Mat();
    }
}

QImage mat_to_qimage(Mat &mat) {
    int width, height;
    width = mat.cols;
    height = mat.rows;

    QImage img(width, height, QImage::Format_RGB32);

    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            if (mat.type()==CV_8UC1) {
                int pixel = mat.at<uchar>(i, j);
                img.setPixel(j, i, qRgb(pixel, pixel, pixel));
            } else if (mat.type()==CV_8UC4) {
                Vec4b pixel = mat.at<Vec4b>(i, j);
                img.setPixel(j, i, qRgba(pixel[2], pixel[1], pixel[0], pixel[3]));
            }
        }
    }

    return img;
}

QImage psdcolor(QImage &img, string lcolor, string rcolor) {
    QColor lc, rc;
    QVector<QRgb> color_table;
    QImage img_out(img.width(), img.height(), QImage::Format_RGB32);

    lc.setNamedColor(lcolor.c_str()); rc.setNamedColor(rcolor.c_str());
    color_table.reserve(256);
    for(int i=0; i<256; ++i) {
        int r, g, b;
        r = (rc.red()-lc.red())*i/255.0 + lc.red();
        g = (rc.green()-lc.green())*i/255.0 + lc.green();
        b = (rc.blue()-lc.blue())*i/255.0 + lc.blue();
        color_table.push_back(qRgb(r, g, b));
    }

    for(int i=0; i<img.height(); ++i) {
        for(int j=0; j<img.width(); ++j) {
            int pixel = qGray(img.pixel(j, i));
            img_out.setPixel(j, i, (color_table[pixel]));
        }
    }
    return img_out;
}

QImage image_segmentation(QImage &img, int k) {
    Mat mat, best_labels, centers, mat_out;
    int rows, cols, size;
    Vec4f color[k];
    int count[k] = { 0 };
    QImage img_out(img.width(), img.height(), QImage::Format_RGB32);
    TermCriteria tc(TermCriteria::EPS+TermCriteria::MAX_ITER, 10, 1.0);

    mat = qimage_to_mat(img);
    rows = mat.rows;
    cols = mat.cols;
    size = rows*cols;

    mat.convertTo(mat, CV_32FC4);
    mat = mat.reshape(0, size);
    kmeans(mat, k, best_labels, tc, 10, KMEANS_PP_CENTERS, centers);
    
    for (int i=0; i<size; ++i) {
        int label;
        label = best_labels.at<int>(i);
        color[label] += mat.at<Vec4f>(i, 0); 
        ++count[label];
    }
    for (int i=0; i<k; ++i) color[i] /= count[i];

    mat_out = Mat(size, 1, CV_32FC4);
    for (int i=0; i<size; ++i) {
        int label;
        label = best_labels.at<int>(i);
        mat_out.at<Vec4f>(i) = color[label];
    }
    mat_out = mat_out.reshape(0, rows);

    mat_out.convertTo(mat_out, CV_8UC4);
    img_out = mat_to_qimage(mat_out);    
    return img_out;
}

int main(int argc, char *argv[]) {
    string filename, cmd;
    QImage img_out;

    if (argc < 3) {
        cout << "Usage: " << argv[0] << " psdcolor <image> <lcolor> <rcolor>" << endl;
        cout << "Usage: " << argv[0] << " is <image> <k>" << endl;
    }

    cmd = argv[1];

    if (cmd == "psdcolor") {
        if (argc != 5) {
            cout << "Usage: " << argv[0] << " psdcolor <image> <lcolor> <rcolor>" << endl;
            return 1;
        }

        string lcolor, rcolor;

        filename = argv[2];
        lcolor = "#"+string(argv[3]);
        rcolor = "#"+string(argv[4]);

        QImage img(filename.c_str());
        img = img.convertToFormat(QImage::Format_Grayscale8);
        img_out = psdcolor(img, lcolor, rcolor);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + "_" + argv[4] + ".jpg";

    }
    else if (cmd == "is") {
        if (argc != 4) {
            cout << "Usage: " << argv[0] << " is <image> <k>" << endl;
            return 1;
        }

        int k;
        
        filename = argv[2];
        k = atoi(argv[3]);
        QImage img(filename.c_str());
        img_out = image_segmentation(img, k);

        filename = 
            filename.substr(0, filename.find_last_of('.')) +
            "_" + argv[1] + "_" + argv[3] + ".jpg";
    }
    img_out.save(filename.c_str());
    return 0;
}