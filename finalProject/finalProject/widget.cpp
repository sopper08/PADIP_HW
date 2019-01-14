#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::display_choosen_region(int x,int y){
    string str;
    str = to_string(x)+", "+to_string(y);
    ui->label->setText(QString::fromStdString(str));
}

Widget::~Widget()
{
    delete ui;
}
