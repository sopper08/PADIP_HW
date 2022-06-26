#include <iostream>
#include <numeric>
#include <assert.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat dwt(Mat &mat, float *phi, float *psi) {
    assert(mat.type()==CV_32FC1);
    int rows = mat.rows; int cols = mat.cols;
    Mat l_mat = Mat::zeros(rows, cols/2, CV_32FC1);
    Mat h_mat = Mat::zeros(rows, cols/2, CV_32FC1);
    Mat dwt_mat = Mat::zeros(rows, cols, CV_32FC1);
    Mat ll_mat(dwt_mat, Rect(     0,      0, cols/2, rows/2));
    Mat hl_mat(dwt_mat, Rect(cols/2,      0, cols/2, rows/2));
    Mat lh_mat(dwt_mat, Rect(     0, rows/2, cols/2, rows/2));
    Mat hh_mat(dwt_mat, Rect(cols/2, rows/2, cols/2, rows/2));

    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols/2; ++j) {
            float pixel_0, pixel_1;
            pixel_0 = mat.at<float>(i, j*2);
            pixel_1 = mat.at<float>(i, j*2);
            l_mat.at<float>(i, j) = pixel_0/sqrt(2)+pixel_1/sqrt(2);
            h_mat.at<float>(i, j) = pixel_0/sqrt(2)-pixel_1/sqrt(2);
        }
    }
    for(int i=0; i<rows/2; ++i) {
        for(int j=0; j<cols/2; ++j) {
            float l_pixel_0, l_pixel_1, h_pixel_0, h_pixel_1;
            l_pixel_0 = l_mat.at<float>(i*2, j);
            l_pixel_1 = l_mat.at<float>(i*2+1, j);
            ll_mat.at<float>(i, j) = l_pixel_0*phi[1]+l_pixel_1*phi[0];
            hl_mat.at<float>(i, j) = l_pixel_0*psi[1]+l_pixel_1*psi[0];

            h_pixel_0 = h_mat.at<float>(i*2, j);
            h_pixel_1 = h_mat.at<float>(i*2+1, j);
            lh_mat.at<float>(i, j) = h_pixel_0*phi[1]+h_pixel_1*phi[0];
            hh_mat.at<float>(i, j) = h_pixel_0*psi[1]+h_pixel_1*psi[0];
        }
    }

    return dwt_mat;
}

Mat inverse_dwt(Mat &dwt_mat, float *phi, float *psi) {
    assert(dwt_mat.type()==CV_32FC1);
    int rows = dwt_mat.rows; int cols = dwt_mat.cols;

    Mat ll_mat(dwt_mat, Rect(     0,      0, cols/2, rows/2));
    Mat hl_mat(dwt_mat, Rect(cols/2,      0, cols/2, rows/2));
    Mat lh_mat(dwt_mat, Rect(     0, rows/2, cols/2, rows/2));
    Mat hh_mat(dwt_mat, Rect(cols/2, rows/2, cols/2, rows/2));
    Mat l_mat = Mat::zeros(rows, cols/2, CV_32FC1);
    Mat h_mat = Mat::zeros(rows, cols/2, CV_32FC1);
    Mat inverse_mat = Mat::zeros(rows, cols, CV_32FC1);

    for(int j=0; j<cols/2; ++j) {
        for(int i=0; i<rows; ++i) {
            float l_pixel, h_pixel;
            l_pixel = ll_mat.at<float>(i/2, j)*phi[i%2];
            h_pixel = lh_mat.at<float>(i/2, j)*psi[i%2];
            l_mat.at<float>(i, j) = l_pixel+h_pixel;
            l_pixel = hl_mat.at<float>(i/2, j)*phi[i%2];
            h_pixel = hh_mat.at<float>(i/2, j)*psi[i%2];
            h_mat.at<float>(i, j) = l_pixel+h_pixel;
        }
    }
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            float l_pixel, h_pixel;
            l_pixel = l_mat.at<float>(i, j/2)*phi[i%2];
            h_pixel = h_mat.at<float>(i, j/2)*psi[i%2];
            inverse_mat.at<float>(i, j) = l_pixel+h_pixel;
        }
    }

    return inverse_mat;
}

Mat haar_dwt(Mat &mat) {
    float phi[] = { 1/sqrt(2), 1/sqrt(2) };
    float psi[] = { -1/sqrt(2), 1/sqrt(2) };
    return dwt(mat, phi, psi);
}

Mat inverse_haar_dwt(Mat &mat) {
    float phi[] = { 1/sqrt(2), 1/sqrt(2) };
    float psi[] = { 1/sqrt(2), -1/sqrt(2) };
    return inverse_dwt(mat, phi, psi);
}

Mat image_fusion(vector<Mat> &mats) {
    vector<Mat> haar_mats;
    int rows = mats[0].rows; int cols = mats[0].cols;
    Mat fusion_mat = Mat::zeros(rows, cols, CV_32FC1);
    for(auto it=mats.begin(); it!=mats.end(); ++it) {
        Mat mat = haar_dwt((*it));
        haar_mats.push_back(mat);
    }
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            vector<float> pixels;
            for(auto it=haar_mats.begin(); it!=haar_mats.end(); ++it) {
                pixels.push_back((*it).at<float>(i, j));
            }
            if ((i<rows/2)&&(j<cols/2)) {
                fusion_mat.at<float>(i, j) = accumulate(pixels.begin(), pixels.end(), 0)/float(pixels.size());
            }
            else {
                fusion_mat.at<float>(i, j) = *max_element(pixels.begin(), pixels.end());
            }
        }
    }
    return inverse_haar_dwt(fusion_mat);
}

int main(int argc, char *argv[]) {
    string filename, cmd;
    if (argc < 3) {
        // cout << "Usage: " << argv[0] << " if <img1> <img2> ..." << endl;
        exit(1);
    }

    cmd = argv[1];
    if (cmd=="if") {
        if (argc < 4) {
            cout << "Usage: " << argv[0] << " if <img1> <img2> ..." << endl;
            exit(1);
        }
        vector<Mat> mats;
        for(int i=2; i<argc; ++i) {
            Mat mat = imread(argv[i], IMREAD_GRAYSCALE);
            mat.convertTo(mat, CV_32FC1);
            mats.push_back(mat);
        }
        Mat mat = image_fusion(mats);
        mat.convertTo(mat, CV_8UC1);

        filename = string(argv[2]);
        filename = filename.substr(0, filename.find_last_of('/')+1) + "image_fusion" + ".jpg";
        imwrite(filename, mat);
    }
    else {
        // cout << "Usage: " << argv[0] << " if <img1> <img2> ..." << endl;
        exit(1);
    }



    // imshow("123", mat);
    // waitKey(0);

    return 0;
}