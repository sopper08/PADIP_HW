#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // CONFIG
    ui->setupUi(this);
    ui->label_GBA_h->setVisible(false);
    ui->label_GAA_h->setVisible(false);
    ui->label_GB_h->setVisible(false);
    ui->label_GA_h->setVisible(false);
    ui->groupBox_ADJ_TH->setVisible(false);
    ui->pushButton_ADJ_H->setVisible(false);

    // histograms_arr: all histograms
    histograms_arr[0] = ui->label_GA_h;
    histograms_arr[1] = ui->label_GAA_h;
    histograms_arr[2] = ui->label_GB_h;
    histograms_arr[3] = ui->label_GBA_h;
    // convertBtn_arr: all convert button
    convertBtn_arr[0] = ui->toolButton_OI;
    convertBtn_arr[1] = ui->toolButton_GA;
    convertBtn_arr[2] = ui->toolButton_GAA;
    convertBtn_arr[3] = ui->toolButton_GB;
    convertBtn_arr[4] = ui->toolButton_GBA;

    //connect
    for(int i=0;i<5;i++){
        connect(convertBtn_arr[i], SIGNAL(pressed()), this, SLOT(set_histogram_visble_true()));
        connect(convertBtn_arr[i], SIGNAL(released()), this, SLOT(set_histogram_visble_false()));
    }
    connect(ui->comboBox_ADJ, SIGNAL(activated(int)), this, SLOT(set_ADJ_visible(int)));
    connect(ui->pushButton_OI_CF, SIGNAL(clicked()), this, SLOT(choose_source()));
    connect(ui->pushButton_convert, SIGNAL(clicked()), this, SLOT(convert_to_grayscaleI()));
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(display_compareImg(bool)));
    connect(ui->horizontalSlider_ADJ_TH, SIGNAL(valueChanged(int)), this, SLOT(set_value_of_threshold(int)));
//    connect(ui->pushButton_Run, SIGNAL(clicked()), this, SLOT(exec_threshold_func()));
}
void Widget::set_value_of_threshold(int val){
    valThreshold = val;
    ui->lcdNumber_THRE->display(val);
    exec_threshold_func();
}

void Widget::exec_threshold_func(){
    QImage thre_gaaImg = gaaImg;
    QImage thre_gbaImg = gbaImg;
    int width = thre_gaaImg.width();
    int height = thre_gaaImg.height();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            QRgb qrgb_perPix_ga = thre_gaaImg.pixel(i, j);
            if(qRed(qrgb_perPix_ga)>=valThreshold) qrgb_perPix_ga=qRgb(255,255,255);
            else qrgb_perPix_ga=qRgb(0,0,0);
            thre_gaaImg.setPixel(i, j, qRgb(qrgb_perPix_ga, qrgb_perPix_ga, qrgb_perPix_ga));
            QRgb qrgb_perPix_gb = thre_gbaImg.pixel(i, j);
            if(qRed(qrgb_perPix_gb)>=valThreshold) qrgb_perPix_gb=qRgb(255,255,255);
            else qrgb_perPix_gb=qRgb(0,0,0);
            thre_gbaImg.setPixel(i, j, qRgb(qrgb_perPix_gb, qrgb_perPix_gb, qrgb_perPix_gb));
        }
    }
    ui->label_GAA_i->setPixmap(QPixmap::fromImage(thre_gaaImg.scaled(400,400,Qt::KeepAspectRatio)));
    ui->label_GBA_i->setPixmap(QPixmap::fromImage(thre_gbaImg.scaled(400,400,Qt::KeepAspectRatio)));

}

void Widget::display_compareImg(bool b){
    switch (b) {
    case true:
        ui->label_GA_i->setPixmap(QPixmap::fromImage(compareImg.scaled(400,400,Qt::KeepAspectRatio)));
        ui->label_GB_i->setPixmap(QPixmap::fromImage(compareImg.scaled(400,400,Qt::KeepAspectRatio)));
        break;
    case false:
        ui->label_GA_i->setPixmap(QPixmap::fromImage(gaImg.scaled(400,400,Qt::KeepAspectRatio)));
        ui->label_GB_i->setPixmap(QPixmap::fromImage(gbImg.scaled(400,400,Qt::KeepAspectRatio)));
    default:
        break;
    }
}

void Widget::choose_source(){
//    choose_image(tr("Choose your BMP or JPEG image."), &oriImg, ui->graphicsView_OI_i);
    QString fileName = QFileDialog::getOpenFileName(this, "Choose your BMP or JPEG image.");
    if(!fileName.isEmpty()){
        oriImg.load(fileName);
        QImage resizeImg = oriImg.scaled(400,400,Qt::KeepAspectRatio);
        ui->label_OI_i->setPixmap(QPixmap::fromImage(resizeImg));
        int width = resizeImg.width();
        int height = resizeImg.height();
        string str = to_string(width)+" x "+to_string(height);
        ui->label_OI_WH->setText(QString::fromStdString(str));
    }
}

void Widget::set_ADJ_visible(int state){
//    cout << state << endl;
    switch (state) {
    case 0:
        ui->frame_ADJ_SA->setVisible(true);
        ui->groupBox_ADJ_TH->setVisible(false);
        ui->pushButton_ADJ_H->setVisible(false);
        break;
    case 1:
        ui->frame_ADJ_SA->setVisible(false);
        ui->groupBox_ADJ_TH->setVisible(true);
        ui->pushButton_ADJ_H->setVisible(false);
        break;
    case 2:
        ui->frame_ADJ_SA->setVisible(false);
        ui->groupBox_ADJ_TH->setVisible(false);
        ui->pushButton_ADJ_H->setVisible(true);
        break;
    default:
        break;
    }
}

void Widget::set_histogram_visble_true(){
    for(int i=0;i<4;i++){
        histograms_arr[i]->setVisible(true);
    }
}

void Widget::set_histogram_visble_false(){
    for(int i=0;i<4;i++){
        histograms_arr[i]->setVisible(false);
    }
}

void Widget::convert_to_grayscaleI(){
    int oriWidth = oriImg.width();
    int oriHeight = oriImg.height();
    gaImg = QImage(QSize(oriWidth, oriHeight),QImage::Format_RGB32);
    gbImg = QImage(QSize(oriWidth, oriHeight),QImage::Format_RGB32);
    gaaImg = QImage(QSize(oriWidth, oriHeight),QImage::Format_RGB32);
    gbaImg = QImage(QSize(oriWidth, oriHeight),QImage::Format_RGB32);
    compareImg = QImage(QSize(oriWidth, oriHeight),QImage::Format_RGB32);
    for(int i=0;i<oriWidth;i++){
        for(int j=0;j<oriHeight;j++){
            QRgb qrgb_perPix = oriImg.pixel(i, j);
            int graya_pix = (qRed(qrgb_perPix)+qGreen(qrgb_perPix)+qBlue(qrgb_perPix))/3;
            int grayb_pix = (0.299*qRed(qrgb_perPix)+0.587*qGreen(qrgb_perPix)+0.114*qBlue(qrgb_perPix));
            int compare_pix = (graya_pix-grayb_pix)+50;
            if(compare_pix<0) compare_pix=-compare_pix;
            gaImg.setPixel(i, j, qRgb(graya_pix, graya_pix, graya_pix));
            gbImg.setPixel(i, j, qRgb(grayb_pix, grayb_pix, grayb_pix));
            gaaImg.setPixel(i, j, qRgb(graya_pix, graya_pix, graya_pix));
            gbaImg.setPixel(i, j, qRgb(grayb_pix, grayb_pix, grayb_pix));
            compareImg.setPixel(i, j, qRgb(compare_pix, compare_pix, compare_pix));
        }
        ui->progressBar->setValue(100*i/oriHeight+1);
//        cout << i << endl;
    }
    ui->label_GA_i->setPixmap(QPixmap::fromImage(gaImg.scaled(400,400,Qt::KeepAspectRatio)));
    ui->label_GB_i->setPixmap(QPixmap::fromImage(gbImg.scaled(400,400,Qt::KeepAspectRatio)));
    ui->label_GAA_i->setPixmap(QPixmap::fromImage(gaaImg.scaled(400,400,Qt::KeepAspectRatio)));
    ui->label_GBA_i->setPixmap(QPixmap::fromImage(gbaImg.scaled(400,400,Qt::KeepAspectRatio)));
//    ui->label_GA_i->setVisible(true);
}

Widget::~Widget()
{
    delete ui;
}
