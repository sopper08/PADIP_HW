#include "widget.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
