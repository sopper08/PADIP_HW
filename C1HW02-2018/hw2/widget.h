#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QGraphicsView>
#include <QToolButton>
#include <iostream>
#include <QLabel>
#include <QFileDialog>
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


private:
    Ui::Widget *ui;
    QLabel* histograms_arr[4];
    QToolButton* convertBtn_arr[5];
//    void choose_image(const QString &title, QImage* image, QGraphicsView* QGView);
//    void load_image(const QString &fileName, QImage* image, QGraphicsView* QGView);
    QImage oriImg;
    QImage gaImg;
    QImage gbImg;
    QImage compareImg;
    QImage gaaImg;
    QImage gbaImg;
    int valThreshold;
    void exec_threshold_func();

};

#endif // WIDGET_H
