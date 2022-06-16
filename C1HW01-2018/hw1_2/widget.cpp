#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->groupBox_5->setVisible(false);
    ui->groupBox_7->setVisible(false);
    ui->groupBox_8->setVisible(false);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(choose_source()));
    connect(ui->radioButton, SIGNAL(toggled(bool)), this, SLOT(turn_state_0()));
    connect(ui->radioButton_2, SIGNAL(toggled(bool)), this, SLOT(turn_state_1()));
    connect(ui->radioButton_3, SIGNAL(toggled(bool)), this, SLOT(turn_state_2()));
    connect(ui->radioButton_4, SIGNAL(toggled(bool)), this, SLOT(turn_state_3()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(compute()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(choose_source1()));
}

void Widget::turn_state_0(){
    funcStat = 0;
    ui->groupBox_5->setVisible(true);
    ui->groupBox_7->setVisible(false);
    ui->groupBox_8->setVisible(false);
    set_spinbox_region(31, -31);
    ui->label_3->setText(tr("min= -31"));
    ui->label_4->setText(tr("max= 31"));
//    ui->groupBox_2->setGeometry(QRect(30,340,981,531));
}

void Widget::turn_state_1(){
    funcStat = 1;
    ui->groupBox_5->setVisible(true);
    ui->groupBox_7->setVisible(false);
    ui->groupBox_8->setVisible(false);
    set_spinbox_region(100, 0.01);
    ui->label_3->setText(tr("min= 0.01"));
    ui->label_4->setText(tr("max= 100"));
//    ui->groupBox_2->setGeometry(QRect(30,340,981,531));
}

void Widget::turn_state_2(){
    funcStat = 2;
    ui->groupBox_5->setVisible(false);
    ui->groupBox_7->setVisible(true);
    ui->groupBox_8->setVisible(true);
//    ui->groupBox_2->setGeometry(QRect(350,340,661,531));
}

void Widget::turn_state_3(){
    funcStat = 3;
    ui->groupBox_5->setVisible(false);
    ui->groupBox_7->setVisible(false);
    ui->groupBox_8->setVisible(false);
//    ui->groupBox_2->setGeometry(QRect(30,340,981,531));
}

void Widget::compute(){
    for(int i=0;i<32;i++){
        histogram[i]=0;
    }

    constant = ui->doubleSpinBox->value();
    cout << constant << endl;
    if(funcStat==0){
//        cout << "0" << endl;
        add_sub_functions(&srcImg2, constant);
        ui->label_2->setBaseSize(QSize(300, 300));
        QImage imgResize = srcImg2.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
        ui->label_2->setPixmap(QPixmap::fromImage(imgResize));
    }else if(funcStat==1){
        mul_sub_functions(&srcImg2, constant);
        ui->label_2->setBaseSize(QSize(300, 300));
        QImage imgResize = srcImg2.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
        ui->label_2->setPixmap(QPixmap::fromImage(imgResize));
    }else if(funcStat==2){
        average_of_the_images(&srcImg2);
        ui->label_2->setBaseSize(QSize(300, 300));
        QImage imgResize = srcImg2.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
        ui->label_2->setPixmap(QPixmap::fromImage(imgResize));
    }else{
        cout << funcStat << endl;
        move_the_image(&srcImg2);
        ui->label_2->setBaseSize(QSize(300, 300));
        QImage imgResize = srcImg2.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
        ui->label_2->setPixmap(QPixmap::fromImage(imgResize));
    }
    ui->label_2->setVisible(true);
    create_histogram();
}

void Widget::average_of_the_images(QImage* image){
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            QRgb qrgb_avg = (srcImg1.pixel(j, i) + srcImg3.pixel(j, i)) / 2;
            int r = qRed(qrgb_avg)/8;
            histogram[r]++;
            image->setPixel(j, i, qrgb_avg);
        }
    }

}

void Widget::move_the_image(QImage* image){
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            QRgb qrgb_image = srcImg1.pixel(j, i);
            if(j<1){
                image->setPixel(j, i, qrgb_image);
            }else{
                QRgb qrgb_image_5 = srcImg1.pixel(j-1, i);
                int result = qGray(qrgb_image) - qGray(qrgb_image_5);
                if(result<0){
                    result=-result;
                }
                int r = result/8;
                histogram[r]++;
                image->setPixel(j, i, qRgb(result, result, result));
            }
        }
    }
}

void Widget::add_sub_functions(QImage* image, float constant){
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            QRgb qrgb_image = srcImg1.pixel(j, i);
            int qray_result = qGray(qRed(qrgb_image), qGreen(qrgb_image), qBlue(qrgb_image)) + constant*8;
            if(qray_result>255){
                qray_result=255;
            }else if(qray_result<0){
                qray_result=0;
            }
            int r = qray_result/8;
            histogram[r]++;
            image->setPixel(j, i, qRgb(qray_result, qray_result, qray_result));
        }
    }
}

void Widget::mul_sub_functions(QImage* image, float constant){

    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            QRgb qrgb_image = srcImg1.pixel(j, i);
            int qray_result = qGray(qRed(qrgb_image), qGreen(qrgb_image), qBlue(qrgb_image)) * constant;
            if(qray_result>255){
                qray_result=255;
            }
            int r = qray_result/8;
            histogram[r]++;
            image->setPixel(j, i, qRgb(qray_result, qray_result, qray_result));
        }
    }
}

void Widget::set_spinbox_region(float max, float min){
    ui->doubleSpinBox->setMaximum(max);
    ui->doubleSpinBox->setMinimum(min);
}


void Widget::reset(){
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->pushButton->setVisible(true);
    for(int i=0;i<32;i++){
        histogram[i]=0;
    }
    funcStat = 3;
    constant = 1;
    ui->radioButton_4->setChecked(true);
    create_histogram();
}

void Widget::choose_source1(){
    choose_image(tr("Choose your .64 image."), &srcImg3, ui->label_6);
    ui->label_6->setVisible(true);
}

void Widget::choose_source(){
    choose_image(tr("Choose your .64 image."), &srcImg1, ui->label);
    ui->label->setVisible(true);
    ui->pushButton->setVisible(false);
}

void Widget::choose_image(const QString &title, QImage* image, QLabel* label){
    QString fileName = QFileDialog::getOpenFileName(this, title);
    if (!fileName.isEmpty()){
        load_image(fileName, image, label);
    }
}

void Widget::load_image(const QString &fileName, QImage* image, QLabel *label){
//    image->load(fileName);
    convert_file_to_QImage(fileName, image);
    label->setBaseSize(QSize(300, 300));
    QImage imgResize = image->scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(imgResize));
}

int Widget::convert_16_to_10(char c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }else{
        return c-'A'+10;
    }
}

vector< vector<char> > Widget::read_file_to_2D_vector(const QString &fileName){
    ifstream myfile(fileName.toStdString().c_str());
    string line;
    vector< vector<char> > table;
    while(getline(myfile, line)){
        vector<char> row;
        istringstream w(line);
        char c;
        // w>>s 轉換類型成 string
        while(w>>c){
            row.push_back(c);
        }
        table.push_back(row);
    }
    return table;
}

void Widget::convert_file_to_QImage(const QString &fileName, QImage* image){
    vector< vector<char> > image_vec = read_file_to_2D_vector(fileName);
    for(int i=0;i<64;i++){
        for(int j=0;j<64;j++){
            int tmp_int = convert_16_to_10(image_vec[i][j]);
            image->setPixel(j, i, qRgb(tmp_int*8, tmp_int*8, tmp_int*8));
        }
    }
}

void Widget::create_histogram(){



    QChart *chart = new QChart();
    QBarSet *set0 = new QBarSet("Histogram");

    for(int i=0;i<32;i++){
        *set0 << histogram[i];
    }

    QStringList categories;
    QString column = "0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V";
    categories = column.split(",",QString::SkipEmptyParts);

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(false);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    while(!ui->horizontalLayout->isEmpty())
    {
        ui->horizontalLayout->removeItem(ui->horizontalLayout->itemAt(0));
    }
    ui->horizontalLayout->addWidget(chartView);
}

Widget::~Widget()
{
    delete ui;
}
