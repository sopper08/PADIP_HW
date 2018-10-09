#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QGraphicsView>
#include <QToolButton>
#include <iostream>
#include <QLabel>
#include <QFileDialog>
#include <QtCharts>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
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
    void set_histogram_visble_true();
    void set_histogram_visble_false();
    void set_ADJ_visible(int state);
    void choose_source(void);
    void convert_to_grayscaleI(void);
    void display_compareImg(bool);
    void set_value_of_threshold(int);
    void set_value_of_brightness(int);
    void set_value_of_constrast(int);
    void set_value_of_scale(int);
    void display_grayscale(int);
    void test_func();
    void display_HE();

private:
    Ui::Widget *ui;
    QWidget* histograms_arr[4];
    QToolButton* convertBtn_arr[5];
    QImage oriImg;
    QImage gaImg;
    QImage gbImg;
    QImage compareImg;
    QImage gaaImg;
    QImage gbaImg;
    int valThreshold;
    int valBrightness;
    double valContrast=0;
    void exec_threshold_func(int val);
    void exec_ConBri_func();
    void exec_spatial_resolution(int val);
    void create_histogram(QImage* image, QHBoxLayout* layout);
    vector<int> histogram_ga;
    vector<int> histogram_gb;
    int width_g;
    int height_g;
    double valScale;
    QImage exec_HE(vector<int> v, QImage* image);
    void exec_GS(int bits);
};

#endif // WIDGET_H
