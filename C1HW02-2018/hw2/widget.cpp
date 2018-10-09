#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // CONFIG
    ui->setupUi(this);
    ui->lcdNumber_ADJ_ES->display(1);
    // Set visible of histogram: false(initial)
    ui->widget_GA_h->setVisible(false);
    ui->widget_GAA_h->setVisible(false);
    ui->widget_GB_h->setVisible(false);
    ui->widget_GBA_h->setVisible(false);
    // Set visible of the applications(ES&TH&H): false(initial)
    ui->widget_ADJ_ES->setVisible(false);
    ui->groupBox_ADJ_TH->setVisible(false);
    ui->pushButton_ADJ_H->setVisible(false);
    // Set histograms_arr: all histograms
    histograms_arr[0] = ui->widget_GA_h;
    histograms_arr[1] = ui->widget_GAA_h;
    histograms_arr[2] = ui->widget_GB_h;
    histograms_arr[3] = ui->widget_GBA_h;
    // Set convertBtn_arr: all convert button
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
    connect(ui->checkBox_COMPARE, SIGNAL(clicked(bool)), this, SLOT(display_compareImg(bool)));
    connect(ui->horizontalSlider_ADJ_TH, SIGNAL(valueChanged(int)), this, SLOT(set_value_of_threshold(int)));
    connect(ui->verticalSlider_ADJ_SA_BC_B, SIGNAL(valueChanged(int)), this, SLOT(set_value_of_brightness(int)));
    connect(ui->verticalSlider_ADJ_SA_BC_C, SIGNAL(valueChanged(int)), this, SLOT(set_value_of_constrast(int)));
    connect(ui->pushButton_ADJ_H, SIGNAL(clicked()), this, SLOT(display_HE()));
    connect(ui->verticalSlider_ADJ_ES, SIGNAL(valueChanged(int)), this, SLOT(set_value_of_scale(int)));
    connect(ui->comboBox_ADJ_ES_GS, SIGNAL(activated(int)), this, SLOT(display_grayscale(int)));
}

/* Choose the image */
void Widget::choose_source(){
    QString fileName = QFileDialog::getOpenFileName(this, "Choose your BMP or JPEG image.");
//    oriImg = QImage(400,400,QImage::Format_RGB32);
    if(!fileName.isEmpty()){
        QImage resizeImg;
        resizeImg.load(fileName);
        oriImg = resizeImg.scaled(400,400,Qt::KeepAspectRatio);
        display_WandH(&oriImg,ui->label_OI_WH_NUM);
        ui->label_OI_i->setPixmap(QPixmap::fromImage(oriImg));
    }
}

/* Convert to grayscale Image */
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
            compareImg.setPixel(i, j, qRgb(compare_pix, compare_pix, compare_pix));
        }
        ui->progressBar->setValue(80*i/oriHeight+1);
    }
    // Initial gaaImg
    gaaImg = gaImg.copy();
    // Initial gbaImg
    gbaImg = gbImg.copy();
    // Display GA
    ui->label_GA_i->setPixmap(QPixmap::fromImage(gaImg.scaled(400,400,Qt::KeepAspectRatio)));
    create_histogram(&gaImg,ui->horizontalLayout_GA_h);
    display_WandH(&gaImg,ui->label_GA_WH_NUM);
    // Display GB
    ui->label_GB_i->setPixmap(QPixmap::fromImage(gbImg.scaled(400,400,Qt::KeepAspectRatio)));
    create_histogram(&gbImg,ui->horizontalLayout_GB_h);
    display_WandH(&gbImg,ui->label_GB_WH_NUM);
    // Display GAA & GBA
    display_A_IandH(&gaaImg,&gbaImg);

    ui->progressBar->setValue(90);
    // Record the gaImg & gbImg histogram value
    histogram_ga = vector<int>(256,0);
    histogram_gb = vector<int>(256,0);
    width_g = gaaImg.width();
    height_g = gaaImg.height();
    for(int i=0;i<width_g;i++){
        for(int j=0;j<height_g;j++){
            int pix = qRed(gaImg.pixel(i,j));
            histogram_ga[pix]++;
            pix = qRed(gbImg.pixel(i,j));
            histogram_gb[pix]++;
        }
    }
    ui->progressBar->setValue(100);
}

/* GUI config */
void Widget::set_ADJ_visible(int state){
//    cout << state << endl;
    switch (state) {
    case 0:
        ui->widget_ADJ_SA->setVisible(true);
        ui->widget_ADJ_ES->setVisible(false);
        ui->groupBox_ADJ_TH->setVisible(false);
        ui->pushButton_ADJ_H->setVisible(false);
        break;
    case 1:
        ui->widget_ADJ_SA->setVisible(false);
        ui->widget_ADJ_ES->setVisible(false);
        ui->groupBox_ADJ_TH->setVisible(true);
        ui->pushButton_ADJ_H->setVisible(false);
        break;
    case 2:
        ui->widget_ADJ_SA->setVisible(false);
        ui->widget_ADJ_ES->setVisible(false);
        ui->groupBox_ADJ_TH->setVisible(false);
        ui->pushButton_ADJ_H->setVisible(true);
        break;
    case 3:
        ui->widget_ADJ_SA->setVisible(false);
        ui->widget_ADJ_ES->setVisible(true);
        ui->groupBox_ADJ_TH->setVisible(false);
        ui->pushButton_ADJ_H->setVisible(false);
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

/* Display the histogram of image*/
void Widget::create_histogram(QImage* image, QHBoxLayout* layout){

    QChart *chart = new QChart();
    QBarSet *set0 = new QBarSet("Histogram");
    set0->setPen(QPen(Qt::SolidLine));
    int width = image->width();
    int height = image->height();
    vector<int> histogram(256,0);
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            int pix = qRed(image->pixel(i,j));
            histogram[pix]++;
        }
    }
    for(int i=0;i<256;i++){
        *set0 << histogram[i];
    }
    QBarSeries* series = new QBarSeries();
    series->append(set0);
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    QValueAxis* axisX = new QValueAxis;
    axisX->setRange(0,255);
    axisX->setTickCount(6);
    chart->createDefaultAxes();
    axisX->setLabelFormat("%d");
    QValueAxis* axisY = new QValueAxis;
    vector<int>::iterator max = max_element(begin(histogram),end(histogram));
    axisY->setRange(0,*max);
    axisY->setTickCount(3);
    axisY->setLabelFormat("%d");

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    while(!layout->isEmpty())
    {
        layout->removeItem(layout->itemAt(0));
    }
    layout->addWidget(chartView);

}

/* Threshold function */
void Widget::set_value_of_threshold(int val){
    ui->lcdNumber_ADJ_TH->display(val);
    exec_threshold_func(val);
}

void Widget::exec_threshold_func(int val){
    int valThreshold = val;
    QImage thre_gaaImg = gaaImg;
    QImage thre_gbaImg = gbaImg;
    int width = thre_gaaImg.width();
    int height = thre_gaaImg.height();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            QRgb qrgb_perPix_ga = thre_gaaImg.pixel(i, j);
            if(qRed(qrgb_perPix_ga)>=valThreshold) qrgb_perPix_ga=qRgb(255,255,255);
            else qrgb_perPix_ga=qRgb(0,0,0);
            thre_gaaImg.setPixel(i, j, qrgb_perPix_ga);
            QRgb qrgb_perPix_gb = thre_gbaImg.pixel(i, j);
            if(qRed(qrgb_perPix_gb)>=valThreshold) qrgb_perPix_gb=qRgb(255,255,255);
            else qrgb_perPix_gb=qRgb(0,0,0);
            thre_gbaImg.setPixel(i, j, qrgb_perPix_gb);
        }
    }
    display_A_IandH(&thre_gaaImg,&thre_gaaImg);
}

/* Spatial resolution */
void Widget::set_value_of_scale(int val){
    ui->lcdNumber_ADJ_ES->display(val);
    exec_spatial_resolution(val);
}

void Widget::exec_spatial_resolution(int val){
    int valScale=val;

    ui->label_GAA_i->setPixmap(QPixmap::fromImage(gaaImg));
    int width = gaImg.width();
    int height = gaImg.height();
    QImage* spatial_gaaimage = new QImage(width*valScale,height*valScale,QImage::Format_RGB32);
    QImage* spatial_gbaimage = new QImage(width*valScale,height*valScale,QImage::Format_RGB32);
    for(int i=0;i<width*valScale;i++){
        for(int j=0;j<height*valScale;j++){
            float a = i/valScale-(int)i/valScale;
            float b = j/valScale-(int)j/valScale;
            float c = 1-a;
            float d = 1-b;
            int x = i/valScale;
            int y = j/valScale;
            if((x+1)>=width&&(y+1)>=height){
                x--;y--;
            }else if((x+1)>=width&&(y+1)<height){
                x--;
            }else if((x+1)<width&&(y+1)>=height){
                y--;
            }
            int setPix = c*d*qRed(gaImg.pixel(x,y))
                        +a*d*qRed(gaImg.pixel(x+1,y))
                        +c*b*qRed(gaImg.pixel(x,y+1))
                        +a*b*qRed(gaImg.pixel(x+1,y+1));
            spatial_gaaimage->setPixel(i,j,qRgb(setPix,setPix,setPix));
            setPix =     c*d*qRed(gbImg.pixel(x,y))
                        +a*d*qRed(gbImg.pixel(x+1,y))
                        +c*b*qRed(gbImg.pixel(x,y+1))
                        +a*b*qRed(gbImg.pixel(x+1,y+1));
            spatial_gbaimage->setPixel(i,j,qRgb(setPix,setPix,setPix));
        }
    }
    ui->label_GAA_i->setPixmap(QPixmap::fromImage(*spatial_gaaimage));
    create_histogram(spatial_gaaimage,ui->horizontalLayout_GAA_h);

    ui->label_GBA_i->setPixmap(QPixmap::fromImage(*spatial_gbaimage));
    create_histogram(spatial_gbaimage,ui->horizontalLayout_GBA_h);

    string str = to_string(width*valScale)+" x "+to_string(height*valScale);
    ui->label_GAA_WH_NUM->setText(QString::fromStdString(str));
    ui->label_GBA_WH_NUM->setText(QString::fromStdString(str));
}

/* Grayscale level */
void Widget::display_grayscale(int val){
    int bits=pow(2,3-val);
    exec_GS(bits);
}

void Widget::exec_GS(int bits){
    QImage GS_gaaImg = gaImg.copy();
    QImage GS_gbaImg = gbImg.copy();
    int width = GS_gaaImg.width();
    int height = GS_gaaImg.height();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            int pix = qRed(GS_gaaImg.pixel(i,j));
            pix /= (256/pow(2,bits));
            int setPix = pix*(256/pow(2,bits));
            GS_gaaImg.setPixel(i,j,qRgb(setPix,setPix,setPix));
            pix = qRed(GS_gbaImg.pixel(i,j));
            pix /= (256/pow(2,bits));
            setPix = pix*(256/pow(2,bits));
            GS_gbaImg.setPixel(i,j,qRgb(setPix,setPix,setPix));
        }
    }
    display_A_IandH(&GS_gaaImg,&GS_gaaImg);
}

/* Brightnes and Constrast */
void Widget::set_value_of_brightness(int val){
    valBrightness = val;
    ui->lcdNumber_ADJ_SA_BC_B->display(valBrightness);
    exec_ConBri_func();
}

void Widget::set_value_of_constrast(int val){
    valContrast = val;
    ui->lcdNumber_ADJ_SA_BC_C->display(valContrast);
    exec_ConBri_func();
}

void Widget::exec_ConBri_func(){
    QImage gaaImg_ConBri = gaImg;
    QImage gbaImg_ConBri = gbImg;
    if(valContrast<0) valContrast=-1/valContrast;
    else if(valContrast==0) valContrast=1;
    int width = gaaImg_ConBri.width();
    int height = gbaImg_ConBri.height();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            int gray_perPix = qRed(gaaImg_ConBri.pixel(i, j));
            double setPix = gray_perPix+valBrightness;
            if(setPix>255) setPix=255;
            else if(setPix<0) setPix=0;
            // norm
            setPix =pow(setPix/255, valContrast)*255;
            gaaImg_ConBri.setPixel(i, j, qRgb(setPix, setPix, setPix));

            gray_perPix = qRed(gbaImg_ConBri.pixel(i, j));
            setPix = gray_perPix+valBrightness;
            if(setPix>255) setPix=255;
            else if(setPix<0) setPix=0;
            // norm
            setPix =pow(setPix/255, valContrast)*255;
            gbaImg_ConBri.setPixel(i, j, qRgb(setPix, setPix, setPix));
        }
    }
    display_A_IandH(&gaaImg_ConBri,&gbaImg_ConBri);
}

/* Histogram equalization */
void Widget::display_HE(){
    QImage tmp_gaa = exec_HE(histogram_ga, &gaImg);
    QImage tmp_gba = exec_HE(histogram_gb, &gbImg);
    display_A_IandH(&tmp_gaa,&tmp_gba);
}

QImage Widget::exec_HE(vector<int> v, QImage* image){
    int size = v.size();
    vector<int> label(size,0);
    cout << size << endl;
    for(int i=0;i<size;i++){
        int tmp = 0;
//        cout << "before:" << i << ":  " << v[i] << endl;
        for(int j=0;j<i+1;j++){
            tmp+=v[j];
        }
        double result = (255*tmp)/(width_g*height_g);
        label[i]=int(result);
//        cout << "after:" << i << ":  " << v[i] << endl;
    }

    QImage* result_image = new QImage(width_g,height_g,QImage::Format_RGB32);
    for(int i=0;i<width_g;i++){
        for(int j=0;j<height_g;j++){
            int setPix = label[qRed(image->pixel(i, j))];
            result_image->setPixel(i, j, qRgb(setPix, setPix, setPix));
        }
    }
    return *result_image;

}

void Widget::test_func(){
//    create_histogram(&gaImg, ui->horizontalLayout_GA_h);
}

void Widget::display_compareImg(bool b){
    if(b){
        ui->label_GA_i->setPixmap(QPixmap::fromImage(compareImg.scaled(400,400,Qt::KeepAspectRatio)));
        ui->label_GB_i->setPixmap(QPixmap::fromImage(compareImg.scaled(400,400,Qt::KeepAspectRatio)));
    }else{
        ui->label_GA_i->setPixmap(QPixmap::fromImage(gaImg.scaled(400,400,Qt::KeepAspectRatio)));
        ui->label_GB_i->setPixmap(QPixmap::fromImage(gbImg.scaled(400,400,Qt::KeepAspectRatio)));
    }
}

/* display Image and Histogram after processing */
void Widget::display_A_IandH(QImage* Image1, QImage* Image2){
    display_WandH(Image1,ui->label_GAA_WH_NUM);
    display_WandH(Image2,ui->label_GBA_WH_NUM);
    ui->label_GAA_i->setPixmap(QPixmap::fromImage(Image1->scaled(400,400,Qt::KeepAspectRatio)));
    create_histogram(Image1,ui->horizontalLayout_GAA_h);
    ui->label_GBA_i->setPixmap(QPixmap::fromImage(Image2->scaled(400,400,Qt::KeepAspectRatio)));
    create_histogram(Image2,ui->horizontalLayout_GBA_h);
}

/* display the W&H of the Image */
void Widget::display_WandH(QImage* image, QLabel* label){
    int width = image->width();
    int height = image->height();
    string str = to_string(width)+" x "+to_string(height);
    label->setText(QString::fromStdString(str));
}

Widget::~Widget()
{
    delete ui;
}
