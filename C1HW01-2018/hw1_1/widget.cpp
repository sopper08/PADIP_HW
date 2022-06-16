#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(choose_source()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(create_histogram()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(reset()));
}

void Widget::reset(){
    ui->label->setVisible(false);
    ui->pushButton->setVisible(true);
    for(int i=0;i<32;i++){
        histogram[i]=0;
    }
    create_histogram();
}

void Widget::choose_source(){
    choose_image(tr("Choose your .64 image."), &srcImg, ui->label);
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

int Widget::ascii_hex_to_int(char c){
    if (c>='0' && c<='9') return c-'0';
    if (c>='A' && c<='F') return c-'A'+10;
    return 0;
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
    for(int i=0;i<image_vec.size();i++){
        for(int j=0;j<image_vec[i].size();j++){
            int tmp_int = ascii_hex_to_int(image_vec[i][j]);
            histogram[tmp_int]++;
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
    QString column = "1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V";
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
