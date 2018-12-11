#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
/*
    Mat src = imread("./img/clock2.JPG",0);
//    imshow("src",src);
//    waitKey(0);
//    exit(1);
    Point2f srcTri[] = {
        Point2f(0,0),
        Point2f(src.cols-1,0),
        Point2f(src.cols-1,src.rows-1),
        Point2f(0,src.rows-1)


    };

    Point2f dstTri[] = {
        Point2f((src.cols-1)*0.0,(src.rows-1)*0.0),
        Point2f((src.cols-1)*1.0,(src.rows-1)*0.0),
        Point2f((src.cols-1)*0.8,(src.rows-1)*0.8),
        Point2f((src.cols-1)*0.2,(src.rows-1)*0.8)
    };

    Mat warp_mat = getPerspectiveTransform(srcTri,dstTri);

    Mat dst, dst2, dst3;
    warpPerspective(src,dst,warp_mat,src.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());
    for(int i=0;i<4;i++)
        circle(dst,dstTri[i],5,Scalar(255,0,255),-1,CV_AA);
//    imshow("123", dst);

    dst2.create(src.size(), src.type());
    int i,j;
    for(i=0;i<src.rows;i++){
        for(j=0;j<src.cols;j++){
            int i_star, j_star;
            i_star = i + 10*sin((double)j/10.0);
            j_star = j + 10*sin((double)i/10.0);
            if(i_star>=0&&j_star>=0&&i_star<src.rows&&j_star<src.cols){
                uchar pixel;
                pixel = src.at<uchar>(i_star,j_star);
                dst2.at<uchar>(i,j) = pixel;
            }
        }
    }
//    imshow("456",dst2);
    dst3.create(src.size(), src.type());
    int rows = src.rows;
    int cols = src.cols;
    for(i=0;i<src.rows;i++){
        for(j=0;j<src.cols;j++){
            int i_star, j_star;
            double i_norm, j_norm, i_sqaure, j_sqaure, x, y;
            i_norm = (double)i/(double)rows*2-1.0;
            j_norm = (double)j/(double)cols*2-1.0;
            i_sqaure = pow(i_norm,2);
            j_sqaure = pow(j_norm,2);
            x = 0.5*sqrt(2.0+i_sqaure-j_sqaure+2.0*sqrt(2)*i_norm)-0.5*sqrt(2.0+i_sqaure-j_sqaure-2.0*sqrt(2)*i_norm);
            y = 0.5*sqrt(2.0-i_sqaure+j_sqaure+2.0*sqrt(2)*j_norm)-0.5*sqrt(2.0-i_sqaure+j_sqaure-2.0*sqrt(2)*j_norm);
            i_star = (x+1.0)*rows/2;
            j_star = (y+1.0)*cols/2;;
            if(i_star>=0&&j_star>=0&&i_star<src.rows&&j_star<src.cols){
                uchar pixel;
                pixel = src.at<uchar>(i_star,j_star);
                dst3.at<uchar>(i,j) = pixel;
            }
        }
    }
//    imshow("456",dst3);

    Mat tmp = Mat::zeros(src.size(), CV_32FC1);
    Mat wavelet = Mat::zeros(src.size(), CV_32FC1);
    Mat imgTmp = Mat_<float>(src);
//    imgTmp.convertTo(imgTmp, CV_32FC1);
    for(i=0;i<imgTmp.rows;i++){
        for(j=0;j<imgTmp.cols/2;j++){
            tmp.at<float>(i,j) = (imgTmp.at<float>(i,2*j)+imgTmp.at<float>(i,2*j+1));
            tmp.at<float>(i,j+imgTmp.cols/2) = (imgTmp.at<float>(i,2*j)-imgTmp.at<float>(i,2*j+1));
        }
    }
    for(i=0;i<imgTmp.rows/2;i++){
        for (j=0;j<imgTmp.cols;j++){
            wavelet.at<float>(i,j) = (tmp.at<float>(2*i,j)+tmp.at<float>(2*i+1,j));
            wavelet.at<float>(i+src.rows/2,j) = (tmp.at<float>(2*i,j)-tmp.at<float>(2*i+1,j));
        }
    }

    Mat reconstructMat = Mat::zeros(src.size(), CV_32FC1);
    Mat reconstructMat_st1 = Mat::zeros(src.size(), CV_32FC1);
    for(i=0;i<wavelet.rows/2;i++){
        for(j=0;j<wavelet.cols;j++){
            reconstructMat_st1.at<float>(2*i,j) = (wavelet.at<float>(i,j) + wavelet.at<float>(i+src.rows/2,j))/2;
            reconstructMat_st1.at<float>(2*i+1,j) = (wavelet.at<float>(i,j) - wavelet.at<float>(i+src.rows/2,j))/2;
        }
    }

    for(i=0;i<wavelet.rows;i++){
        for(j=0;j<wavelet.cols/2;j++){
            reconstructMat.at<float>(i,2*j) = (reconstructMat_st1.at<float>(i,j) + reconstructMat_st1.at<float>(i,j+src.cols/2))/2;
            reconstructMat.at<float>(i,2*j+1) = (reconstructMat_st1.at<float>(i,j) - reconstructMat_st1.at<float>(i,j+src.cols/2))/2;
        }
    }

    reconstructMat.convertTo(reconstructMat,CV_8UC1);
//    imshow("10",reconstructMat);

    Mat ddst, cdst;
    Canny(src, ddst, 50, 200, 3);
    cvtColor(ddst, cdst, CV_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(ddst, lines, 1, CV_PI/180, 50, 50, 10 );
    for( size_t i = 0; i < lines.size(); i++ ){
        Vec4i l = lines[i];
        line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
    }
    imshow("source", src);
    imshow("detected lines", cdst);
    waitKey(0);
*/
    return a.exec();
}
