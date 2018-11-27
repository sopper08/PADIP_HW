#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <QDir>
#include <QLabel>

using namespace std;
using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void runPseudoColor();
    void displayOriIMG(int);
    void colorSegmentation();
    void createColorBar();
    void storeProcessedImg();
    void storeOriImg();

private:
    Ui::Widget *ui;
    struct imgModel{
        Mat rgbPlane;
        Mat cmyPlane;
        Mat hsiPlane;
        Mat xyzPlane;
        Mat labPlane;
        Mat yuvPlane;
    };
    struct imgModel oriImg;
    Mat proImg;
    int picN = 0;
    int colorListMap[10][3] = {
        {255,0,0},
        {255,85,17},
        {255,187,0},
        {187,255,0},
        {0,255,0},
        {0,255,204},
        {0,187,255},
        {0,0,255},
        {119,0,255},
        {204,0,255}
    };
    int colormap[256][3];
    Mat rgb2hsi(Mat);
    Mat rgb2cmy(Mat);
    Mat rgb2xyz(Mat);
    Mat rgb2lab(Mat);
    Mat rgb2yuv(Mat);
    Mat hsi2rgb(Mat);
    void ui_config();
    void dispalyListOfImage(QString);
    struct image{
            QString name;
            QString path;
        };
    vector<image> img_vec;

    QImage Mat2QImage(Mat const& src);
    void displayIMG(QLabel*, QImage);
    void splitAndDisplatPlane(QLabel*, QLabel*, QLabel*, Mat);
    void kmean(int,Mat,Mat);
    QImage colorList(int,int,int);
};

#endif // WIDGET_H
