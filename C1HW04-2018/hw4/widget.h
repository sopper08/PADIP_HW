#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QLabel>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <asmOpenCV.h>

using namespace std;
using namespace cv;
using namespace ASM;

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
    void execute();

private:
    Ui::Widget *ui;
    struct imgSandF{
        Mat img_S;
        Mat img_F;
        Mat img_F_euler;
    }OriImg;

    void ui_config();

    void displayIMG(QLabel*, QImage);

    /*
     * Store the img name&path in "./img" folder, and display them.
     *   - Open the folder: "the/path/of/img/folder",
     *   - Search the *jpg & *bmp image file in the folder.
     *   - Store the by a vector<image>, image include name and path.
     *   - And then, display them at the listWidget_ImageList.
     */
    struct image{
        QString name;
        QString path;
    };
    vector<image> img_vec;
    void dispalyListOfImage(QString);
    QImage Mat2QImage(Mat const& src);
    Mat QImage2Mat(QImage const& src);
    Mat shiftTheFPlane(Mat);



    /*
     *
     * |----------------------------------------------------|
     * |F(u,v) = F{f(x,y)}                                  |
     * |F(u,v) = R(u,v) + jI(u,v)                           |
     * |G(u,v) = H(u,v)F(u,v) = H(u,v)R(u,v) + jH(u,v)I(u,v)|
     * |g(x,y) = F^-1{G(u,v)}                               |
     * |----------------------------------------------------|
     *
     */
    Mat imageFFT(Mat);
    Mat transtoEuler(Mat);
    void displaySpectrumAndPhaseAngle(Mat);
    Mat imageIFFT(Mat);

    /*
     * ILPF: Ideal Lowpass Filter
     *   - Mat: F(u,v)
     *   - int: D0, cut-off freq, 1~500
     *
     *   - return: Mat, H(u,v)R(u,v) + jH(u,v)I(u,v)
     */
    Mat ILPF(Mat, int);

    /*
     * BLPF: Butterworth Lowpass Filter
     *   - Mat: F(u,v)
     *   - int: D0, cut-off freq, 1~500
     *   - int: n, 1~20
     *
     *   - return: Mat, H(u,v)R(u,v) + jH(u,v)I(u,v)
     */
    Mat BLPF(Mat, int, int);

    /*
     * GLPF: Gaussion Lowpass Filter
     *   - Mat: F(u,v)
     *   - int: D0, cut-off freq, 1~500
     *
     *   - return: Mat, H(u,v)R(u,v) + jH(u,v)I(u,v)
     */
    Mat GLPF(Mat, int);

    /*
     * HOMOF: Homemorphic Filter
     *   - Mat: F1(u,v) = F{ln(f(x,y)}
     *   - int: r_H, r_H > 1
     *   - int: r_L, r_L < 1
     *   - int: c
     *   - int: D0, 1~500
     *
     *   - return: Mat, H(u,v)R1(u,v) + jH(u,v)I1(u,v)
     */
    Mat HOMOF(Mat, float, float, float, int);

    /*
     * createMotionBImage: to create a motion blurred image, B(u,v)
     *   - Mat: F(u,v)
     *   - int: a
     *   - int: b
     *   - int: T
     *
     *   - return: Mat, B(u,v)
     */
    Mat createMotionBImage(Mat, float, float, float);

    /*
     * inverseF: Inverse Filter, to remove motion blur
     *   - Mat: B(u,v)
     *   - int: a
     *   - int: b
     *   - int: T
     *
     *   - return: Mat, F_h(u,v)
     */
    Mat inverseF(Mat, float, float, float);

    /*
     * wienerF: Wiener Filter, to remove motion blur
     *   - Mat: B(u,v)
     *   - int: a
     *   - int: b
     *   - int: T
     *   - int: k
     *
     *   - return: Mat, F_h(u,v)
     */
    Mat wienerF(Mat, float, float, float, float);

};

#endif // WIDGET_H