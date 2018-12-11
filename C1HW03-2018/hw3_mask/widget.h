#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <iostream>
#include <vector>
#include <QHBoxLayout>
#include <QLabel>
#include <ctime>
#include <math.h>
#include <algorithm>

using namespace std;

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
    void choose_folder();
    void displayOriIMG(int);
    void setRCCount(int);
    void run();

private:
    Ui::Widget *ui;
    QString folderName;
    struct image{
        QString name;
        QString path;
    };
    vector<image> img_vec;
    QImage* oriImg;
    void displayIMG(QLabel*,int);
    void returnMsg(string);
    int checkTheFunc();
    void edgeDetection(int t);
    void sobel();
    void boxKernal(int);
    void gaussianKernal(int);
    void customKernal(int);
    QImage linearKernalC(vector<vector<double>>,int,bool);
    void nonlinearKernalC(int,int);
//    int _sizeOfKernal=3;
    QImage* addBorder(QImage*, int);
    void ui_config();
};

#endif // WIDGET_H
