#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui_config();
    connect(ui->pushButton_ChooseFolder,SIGNAL(clicked()),this,SLOT(choose_folder()));
    connect(ui->listWidget_ImageList,SIGNAL(currentRowChanged(int)),this,SLOT(displayOriIMG(int)));
    connect(ui->pushButton_Execute,SIGNAL(clicked()),this,SLOT(execute()));
}

void Widget::execute(){
    int i = ui->tabWidget_Func->currentIndex();
    switch (i) {
        case 0:
            cout << "level1: " << 0 << endl;
            break;
        /* LP */
        case 1:{
            cout << "level1: " << 1 << endl;
            int j = ui->tabWidget_Func_LP->currentIndex();
            switch (j) {
                /* ILPF */
                case 0:
                    cout << "level2: " << 0 << endl;
                    break;
                /* BLPF */
                case 1:
                    cout << "level2: " << 1 << endl;
                    break;
                /* GLPF */
                case 2:
                    cout << "level2: " << 2 << endl;
                    break;
                default:
                    break;
            }
            break;
        }
        /* HP */
        case 2:{
            cout << "level1: " << 2 << endl;
            int j = ui->tabWidget_Func_LP->currentIndex();
            switch (j) {
                /* ILPF */
                case 0:
                    cout << "level2: " << 0 << endl;
                    break;
                /* BLPF */
                case 1:
                    cout << "level2: " << 1 << endl;
                    break;
                /* GLPF */
                case 2:
                    cout << "level2: " << 2 << endl;
                    break;
                default:
                    break;
                }
            break;
        }
        case 3:{
            cout << "level1: " << 3 << endl;
            break;
        }
        case 4:{
            cout << "level1: " << 4 << endl;
            break;
        }
        case 5:{
            cout << "level1: " << 5 << endl;
            int j = ui->tabWidget_Func_LP->currentIndex();
            switch (j) {
            case 0:
                cout << "level2: " << 0 << endl;
                break;
            case 1:
                cout << "level2: " << 1 << endl;
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
    }

}

Mat Widget::ILPF(Mat, int){

}

void Widget::ui_config(){
    dispalyListOfImage("./img");
}

void Widget::choose_folder(){
    img_vec.clear();
    while(ui->listWidget_ImageList->count()!=0){
        cout << ui->listWidget_ImageList->count() << endl;
        ui->listWidget_ImageList->takeItem(0);
    }
    QString folderPath = QFileDialog::getExistingDirectory(NULL,tr("選擇資料夾"),"./",QFileDialog::ShowDirsOnly);
    dispalyListOfImage(folderPath);
}

void Widget::displayOriIMG(int d){
    OriImg.img_S = imread(img_vec[d].path.toStdString(), IMREAD_GRAYSCALE);
    QImage oriImg_QIMG = cvMatToQImage(OriImg.img_S);
    displayIMG(ui->label_OriImg, oriImg_QIMG);
    OriImg.img_F = imageFFT(OriImg.img_S);
    OriImg.img_F_euler = transtoEuler(OriImg.img_F);
    Mat img_F_euler[2];
    split(OriImg.img_F_euler,img_F_euler);
    displayIMG(ui->label_OriImgF_S, Mat2QImage(shiftTheFPlane(img_F_euler[0])));

    displayIMG(ui->label_OriImgF_PA, Mat2QImage(shiftTheFPlane(img_F_euler[1])));
}

QImage Widget::Mat2QImage(Mat const& src){
    QImage returnImg = QImage(src.cols, src.rows, QImage::Format_RGB32);
    for(int i=0;i<src.rows;i++){
        const uchar* p;
        p = src.ptr<uchar>(i);
        for(int j=0;j<src.cols;j++){
            int setPixel = int(p[j]);
            returnImg.setPixel(j,i,qRgb(setPixel,setPixel,setPixel));
        }
    }
    return returnImg;
}

Mat Widget::imageFFT(Mat inputImg){
    int m = getOptimalDFTSize(inputImg.rows);
    int n = getOptimalDFTSize(inputImg.cols);
    Mat padded;
    copyMakeBorder(inputImg, padded, 0, m-inputImg.rows, 0, n-inputImg.cols, BORDER_CONSTANT, Scalar::all(0)); //為了效率，所以對影像邊界拓展
    /*  Real: padded, Image: zero */
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    /* Change the complexImg to 2 channels */
    Mat complexImg;
    merge(planes, 2, complexImg);
    /*  dft  */
    dft(complexImg, complexImg);
    return complexImg;
}

Mat Widget::transtoEuler(Mat img_F){
    Mat planes_F[2];
    Mat planes_F_Euler[2];
    split(img_F, planes_F);
    cartToPolar(planes_F[0],planes_F[1],planes_F_Euler[0],planes_F_Euler[1],true);

    planes_F_Euler[0] += Scalar::all(1);
    log(planes_F_Euler[0], planes_F_Euler[0]);

    normalize(planes_F_Euler[0], planes_F_Euler[0], 0, 1, NORM_MINMAX);
    normalize(planes_F_Euler[1], planes_F_Euler[1], 0, 1, NORM_MINMAX);

    Mat result;
    merge(planes_F_Euler,2,result);
    result.convertTo(result, CV_8U, 255);
    return result;
}

Mat Widget::shiftTheFPlane(Mat img_F_euler){
    int cols = img_F_euler.cols;
    int rows = img_F_euler.rows;
    Mat result;
    result.create(2*cols,2*rows,CV_8U);
    Mat q0(result, Rect(0,0,cols,rows));
    Mat q1(result, Rect(cols,0,cols,rows));
    Mat q2(result, Rect(0,rows,cols,rows));
    Mat q3(result, Rect(cols,rows,cols,rows));
    img_F_euler.copyTo(q0);
    img_F_euler.copyTo(q1);
    img_F_euler.copyTo(q2);
    img_F_euler.copyTo(q3);
    return Mat(result, Rect(cols/2,rows/2,cols,rows));

}

void Widget::displayIMG(QLabel* label, QImage img){
    int width = label->width();
    int height = label->height();
    QImage scaledImg = img.scaled(width,height,Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(scaledImg));
}

void Widget::dispalyListOfImage(QString folderPath){
    QDir* dir = new QDir(folderPath);
    /* Filter the *jpg and *.bmp image file. */
    QStringList filter;
    filter << "*.jpg" << "*.bmp";
    /* Create a QList to store the img(s) in the img folder */
    QList<QFileInfo>* fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
    int count = fileInfo->count();
    /* Store them in img_vec(global variable) */
    for(int i=0;i<count;i++){
        QString fileName = fileInfo->at(i).fileName();
        QString path = fileInfo->at(i).filePath();
        struct image img = {fileName,path};
        img_vec.push_back(img);
        ui->listWidget_ImageList->addItem(fileName);
    }
}

Widget::~Widget()
{
    delete ui;
}
