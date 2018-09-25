#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
// QImage 儲存影像的物件
#include <QImage>
// QLabel 用來顯示圖像
#include <QLabel>
// QFileDialog 用來開啟檔案
#include <QFileDialog>
// 顯示直方圖
#include <QtCharts>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
using namespace QtCharts;

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
    void choose_source(void);
    void create_histogram(void);
    void reset(void);

private:
    Ui::Widget *ui;
    // srcImg: 儲存選取的影像
    QImage srcImg = QImage(64,64,QImage::Format_RGB32);

    void convert_file_to_QImage(const QString &fileName, QImage* image);
    void choose_image(const QString &title, QImage* image, QLabel* label);
    void load_image(const QString &fileName, QImage* image, QLabel* label);
    int convert_16_to_10(char c);
    vector<vector<char>> read_file_to_2D_vector(const QString &fileName);
    int histogram[32] = {0};
};

#endif // WIDGET_H
