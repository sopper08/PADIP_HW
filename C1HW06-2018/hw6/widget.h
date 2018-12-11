#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <QDir>
#include <QLabel>
#include <QFileDialog>

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
    void displayOriIMG(int);
    void createTrapImg();
    void createWavyImg();
    void createCirImg();
    void displayFirstImage();
    void displaySecondImage();
    void displayHoughImage();
    void imgFusion();
    void imgHough();

private:
    Ui::Widget *ui;
    Mat oriImg;
    Mat processedImg;
    Mat fusionFirstImg;
    Mat fusionSecondImg;
    Mat houghImg;
    struct image{
            QString name;
            QString path;
        };
    vector<image> img_vec;
    void dispalyListOfImage(QString);
    void ui_config();

    QImage Mat2QImage(Mat const& src);
    void displayIMG(QLabel*, QImage);
    Mat returnHaar(Mat);
    Mat reverseHaar(Mat);
};

#endif // WIDGET_H
