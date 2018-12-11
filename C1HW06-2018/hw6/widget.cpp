#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui_config();
    connect(ui->listWidget_ImageList,SIGNAL(currentRowChanged(int)),this,SLOT(displayOriIMG(int)));
    connect(ui->verticalSlider_h,SIGNAL(valueChanged(int)),ui->lcdNumber_h,SLOT(display(int)));
    connect(ui->verticalSlider_rx,SIGNAL(valueChanged(int)),ui->lcdNumber_rx,SLOT(display(int)));
    connect(ui->verticalSlider_lx,SIGNAL(valueChanged(int)),ui->lcdNumber_lx,SLOT(display(int)));
    connect(ui->pushButton_tra,SIGNAL(clicked()),this,SLOT(createTrapImg()));
    connect(ui->pushButton_wavy,SIGNAL(clicked()),this,SLOT(createWavyImg()));
    connect(ui->pushButton_cir,SIGNAL(clicked()),this,SLOT(createCirImg()));
    connect(ui->verticalSlider_cir_h,SIGNAL(valueChanged(int)),ui->lcdNumber_cir_h,SLOT(display(int)));
    connect(ui->verticalSlider_cir_t,SIGNAL(valueChanged(int)),ui->lcdNumber_cir_t,SLOT(display(int)));
    connect(ui->pushButton_chooseF,SIGNAL(clicked()),this,SLOT(displayFirstImage()));
    connect(ui->pushButton_chooseS,SIGNAL(clicked()),this,SLOT(displaySecondImage()));
    connect(ui->pushButton_imgFusion,SIGNAL(clicked()),this,SLOT(imgFusion()));
    connect(ui->pushButton_houghT_choose,SIGNAL(clicked()),this,SLOT(displayHoughImage()));
    connect(ui->pushButton_houghT_APPLY,SIGNAL(clicked()),this,SLOT(imgHough()));
}

void Widget::imgHough(){
    Mat src = houghImg.clone();
    Mat ddst, cdst;
    Canny(src, ddst, 50, 200, 3);
    cvtColor(ddst, cdst, CV_GRAY2BGR);

    vector<Vec4i> lines;
    HoughLinesP(ddst, lines, 1, CV_PI/180, 50, 50, 10 );
    for( size_t i = 0; i < lines.size(); i++ ){
        Vec4i l = lines[i];
        line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
    }
    displayIMG(ui->label_houghT_proImg,Mat2QImage(cdst));
}

void Widget::imgFusion(){
    Mat f_harr = returnHaar(fusionFirstImg);
    Mat s_harr = returnHaar(fusionSecondImg);
    Mat combine = Mat::zeros(f_harr.size(),CV_32F);
    int i,j;
    int rows,cols;
    rows = fusionFirstImg.rows;
    cols = fusionFirstImg.cols;
    for(i=0;i<rows/2;i++){
        for(j=0;j<cols/2;j++){
            float setP;
            setP = (f_harr.at<float>(i,j) + s_harr.at<float>(i,j))/2;
            combine.at<float>(i,j) = setP;
        }
    }
    for(i=0;i<rows/2;i++){
        for(j=cols/2;j<cols;j++){
            float setP;
            setP = MAX(f_harr.at<float>(i,j),s_harr.at<float>(i,j));
            combine.at<float>(i,j) = setP;
        }
    }
    for(i=rows/2;i<rows;i++){
        for(j=0;j<cols;j++){
            float setP;
            setP = MAX(f_harr.at<float>(i,j),s_harr.at<float>(i,j));
            combine.at<float>(i,j) = setP;
        }
    }
    Mat reverse = reverseHaar(combine);
    reverse.convertTo(reverse,CV_8UC1);
    displayIMG(ui->label_fusionimg,Mat2QImage(reverse));
}

Mat Widget::returnHaar(Mat src){
    Mat tmp = Mat::zeros(src.size(), CV_32FC1);
    Mat wavelet = Mat::zeros(src.size(), CV_32FC1);
    Mat imgTmp = Mat_<float>(src);
    int i,j;
    for(i=0;i<imgTmp.rows;i++){
        for(j=0;j<imgTmp.cols/2;j++){
            tmp.at<float>(i,j) = (imgTmp.at<float>(i,2*j)+imgTmp.at<float>(i,2*j+1));
            tmp.at<float>(i,j+imgTmp.cols/2) = (imgTmp.at<float>(i,2*j)-imgTmp.at<float>(i,2*j+1));
        }
    }
    for(i=0;i<imgTmp.rows/2;i++){
        for (j=0;j<imgTmp.cols;j++){
            wavelet.at<float>(i,j) = (tmp.at<float>(2*i,j)+tmp.at<float>(2*i+1,j));
            wavelet.at<float>(i+src.rows/2,j) = (tmp.at<float>(2*i,j)-tmp.at<float>(2*i+1,j));
        }
    }
    return wavelet;
}

Mat Widget::reverseHaar(Mat wavelet){
    Mat reconstructMat = Mat::zeros(wavelet.size(), CV_32FC1);
    Mat reconstructMat_st1 = Mat::zeros(wavelet.size(), CV_32FC1);
    int i,j;
    for(i=0;i<wavelet.rows/2;i++){
        for(j=0;j<wavelet.cols;j++){
            reconstructMat_st1.at<float>(2*i,j) = (wavelet.at<float>(i,j) + wavelet.at<float>(i+wavelet.rows/2,j))/2;
            reconstructMat_st1.at<float>(2*i+1,j) = (wavelet.at<float>(i,j) - wavelet.at<float>(i+wavelet.rows/2,j))/2;
        }
    }

    for(i=0;i<wavelet.rows;i++){
        for(j=0;j<wavelet.cols/2;j++){
            reconstructMat.at<float>(i,2*j) = (reconstructMat_st1.at<float>(i,j) + reconstructMat_st1.at<float>(i,j+wavelet.cols/2))/2;
            reconstructMat.at<float>(i,2*j+1) = (reconstructMat_st1.at<float>(i,j) - reconstructMat_st1.at<float>(i,j+wavelet.cols/2))/2;
        }
    }
    return reconstructMat;
}

void Widget::displayHoughImage(){
    QString fileName = QFileDialog::getOpenFileName(this, "Choose your BMP or JPEG image.");
    houghImg = imread(fileName.toStdString(),0);
    displayIMG(ui->label_houghT_oriImg,Mat2QImage(houghImg));
}

void Widget::displayFirstImage(){
    QString fileName = QFileDialog::getOpenFileName(this, "Choose your BMP or JPEG image.");
    fusionFirstImg = imread(fileName.toStdString(),0);
    displayIMG(ui->label_choose_f,Mat2QImage(fusionFirstImg));
}

void Widget::displaySecondImage(){
    QString fileName = QFileDialog::getOpenFileName(this, "Choose your BMP or JPEG image.");
    fusionSecondImg = imread(fileName.toStdString(),0);
    displayIMG(ui->label_choose_s,Mat2QImage(fusionSecondImg));
}

void Widget::createCirImg(){
    Mat src = oriImg;
    Mat dst3;
    int i,j;
    dst3.create(src.size(), src.type());
    int rows = src.rows;
    int cols = src.cols;
    for(i=0;i<src.rows;i++){
        for(j=0;j<src.cols;j++){
            int i_star, j_star;
            double i_norm, j_norm, i_sqaure, j_sqaure, x, y;
            i_norm = (double)i/(double)rows*2-1.0;
            j_norm = (double)j/(double)cols*2-1.0;
            i_sqaure = pow(i_norm,2);
            j_sqaure = pow(j_norm,2);
            x = 0.5*sqrt(2.0+i_sqaure-j_sqaure+2.0*sqrt(2)*i_norm)-0.5*sqrt(2.0+i_sqaure-j_sqaure-2.0*sqrt(2)*i_norm);
            y = 0.5*sqrt(2.0-i_sqaure+j_sqaure+2.0*sqrt(2)*j_norm)-0.5*sqrt(2.0-i_sqaure+j_sqaure-2.0*sqrt(2)*j_norm);
            i_star = (x+1.0)*rows/2;
            j_star = (y+1.0)*cols/2;;
            if(i_star>=0&&j_star>=0&&i_star<src.rows&&j_star<src.cols){
                uchar pixel;
                pixel = src.at<uchar>(i_star,j_star);
                dst3.at<uchar>(i,j) = pixel;
            }
        }
    }
    processedImg = Mat::zeros(processedImg.size(),CV_8UC1);
    processedImg = dst3;
    displayIMG(ui->label_proImg,Mat2QImage(dst3));
}

void Widget::createWavyImg(){
    float t,h;
    h = (double)ui->verticalSlider_cir_h->value();
    t = (double)ui->verticalSlider_cir_t->value();
    Mat src = oriImg.clone();
    Mat dst;
    dst.create(src.size(), src.type());
    int i,j;
    for(i=0;i<src.rows;i++){
        for(j=0;j<src.cols;j++){
            int i_star, j_star;
            i_star = i + h*sin((double)j/t);
            j_star = j + h*sin((double)i/t);
            if(i_star>=0&&j_star>=0&&i_star<src.rows&&j_star<src.cols){
                uchar pixel;
                pixel = src.at<uchar>(i_star,j_star);
                dst.at<uchar>(i,j) = pixel;
            }
        }
    }
    processedImg = dst;
    displayIMG(ui->label_proImg,Mat2QImage(processedImg));
//    imshow("456",dst);
}

void Widget::createTrapImg(){
    Mat src = oriImg.clone();
    float rx, lx, h;
    rx = 1.0-(float)ui->verticalSlider_rx->value()/10;
    lx = (float)ui->verticalSlider_lx->value()/10;
    h  = 1.0-(float)ui->verticalSlider_h->value()/10;
    Point2f srcTri[] = {
        Point2f(0,0),
        Point2f(src.cols-1,0),
        Point2f(src.cols-1,src.rows-1),
        Point2f(0,src.rows-1)
    };

    Point2f dstTri[] = {
        Point2f((src.cols-1)*0.0,(src.rows-1)*0.0),
        Point2f((src.cols-1)*1.0,(src.rows-1)*0.0),
        Point2f((src.cols-1)*rx,(src.rows-1)*h),
        Point2f((src.cols-1)*lx,(src.rows-1)*h)
    };

    Mat warp_mat = getPerspectiveTransform(srcTri,dstTri);
    Mat dst;
    warpPerspective(src,dst,warp_mat,src.size(),INTER_LINEAR,BORDER_CONSTANT,Scalar());
    for(int i=0;i<4;i++)
        circle(dst,dstTri[i],5,Scalar(255,0,255),-1,CV_AA);
    processedImg = dst;
    displayIMG(ui->label_proImg,Mat2QImage(processedImg));
}

void Widget::ui_config(){
    dispalyListOfImage("./img");
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

void Widget::displayOriIMG(int d){
    oriImg = imread(img_vec[d].path.toStdString(), 0);
    QImage oriImg_QIMG = Mat2QImage(oriImg);
    displayIMG(ui->label_OriImg, oriImg_QIMG);
}

QImage Widget::Mat2QImage(Mat const& src){
    QImage returnImg = QImage(src.cols, src.rows, QImage::Format_RGB32);
    int channel = src.channels();
    if(channel == 3){
        for(int i=0;i<src.rows;i++){
            for(int j=0;j<src.cols;j++){
                int r,g,b;
                b = src.at<Vec3b>(i,j)[0];
                g = src.at<Vec3b>(i,j)[1];
                r = src.at<Vec3b>(i,j)[2];
                returnImg.setPixel(j,i,qRgb(r,g,b));
            }
        }
        return returnImg;
    }else if(channel==1){
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


}

void Widget::displayIMG(QLabel* label, QImage img){
    int width = label->width();
    int height = label->height();
    QImage scaledImg = img.scaled(width,height,Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(scaledImg));
}


Widget::~Widget()
{
    delete ui;
}
