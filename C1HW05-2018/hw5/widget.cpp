#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui_config();
    connect(ui->listWidget_ImageList,SIGNAL(currentRowChanged(int)),this,SLOT(displayOriIMG(int)));
    connect(ui->pushButton_2,SIGNAL(clicked()),SLOT(close()));
    connect(ui->horizontalSlider_ColorSeg_k,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));
    connect(ui->pushButton_ColorSeg,SIGNAL(clicked()),this,SLOT(colorSegmentation()));
    connect(ui->comboBox_start,SIGNAL(currentIndexChanged(int)),this,SLOT(createColorBar()));
    connect(ui->comboBox_end,SIGNAL(currentIndexChanged(int)),this,SLOT(createColorBar()));
    connect(ui->pushButton_pseudoColor_run, SIGNAL(clicked()),this,SLOT(runPseudoColor()));
    connect(ui->pushButton_ProImg_store,SIGNAL(clicked()),this,SLOT(storeProcessedImg()));
    connect(ui->pushButton_OriImg_store,SIGNAL(clicked()),this,SLOT(storeOriImg()));
}

void Widget::storeOriImg(){
    Mat tempPlane[3];
    string str;
    str = "./processedImg/oriImg_" + to_string(picN) + ".jpg";
    imwrite(str, oriImg.rgbPlane);
    split(oriImg.rgbPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_RGB_B_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_RGB_G_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_RGB_R_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    split(oriImg.cmyPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_CMY_Y_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_CMY_M_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_CMY_C_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    split(oriImg.hsiPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_HSI_H_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_HSI_S_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_HSI_I_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    split(oriImg.xyzPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_XYZ_X_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_XYZ_Y_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_XYZ_Z_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    split(oriImg.labPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_Lab_L_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_Lab_a_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_Lab_b_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    split(oriImg.yuvPlane.clone(),tempPlane);
    str = "./processedImg/oriImg_YUV_Y_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[0]);
    str = "./processedImg/oriImg_YUV_U_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[1]);
    str = "./processedImg/oriImg_YUV_V_" + to_string(picN) + ".jpg";
    imwrite(str, tempPlane[2]);

    picN++;
}

void Widget::storeProcessedImg(){
    Mat img = proImg;
    string str = "./processedImg/processedImg_" + to_string(picN) + ".jpg";
    imwrite(str, img);
    picN++;
}

void Widget::runPseudoColor(){
    Mat greyImg;
    cvtColor(oriImg.rgbPlane, greyImg, CV_BGR2GRAY);
    Mat pseudoColorImg(greyImg.rows,greyImg.cols,CV_8UC3);
    int i,j;
    for(i=0;i<greyImg.rows;i++){
        for(j=0;j<greyImg.cols;j++){
            int oriPixel = greyImg.at<uchar>(i,j);
            pseudoColorImg.at<Vec3b>(i,j)[0] = colormap[oriPixel][2];
            pseudoColorImg.at<Vec3b>(i,j)[1] = colormap[oriPixel][1];
            pseudoColorImg.at<Vec3b>(i,j)[2] = colormap[oriPixel][0];
        }
    }
    proImg = pseudoColorImg.clone();
    displayIMG(ui->label_ProImg,Mat2QImage(pseudoColorImg));
}

void Widget::createColorBar(){
    int begin, process, end;
    begin = ui->comboBox_start->currentIndex();
    end = ui->comboBox_end->currentIndex();
    int* begin_color;
    int* end_color;
    begin_color = colorListMap[begin];
    end_color = colorListMap[end];
    QImage colorbar_img(256,50,QImage::Format_RGB32);
    int i,j;
    for(i=0;i<colorbar_img.height();i++){
        int begin_r, begin_g, begin_b;
        begin_r = begin_color[0];
        begin_g = begin_color[1];
        begin_b = begin_color[2];
        int end_r, end_g, end_b;
        end_r = end_color[0];
        end_g = end_color[1];
        end_b = end_color[2];
        float delta_r, delta_g, delta_b;
        delta_r = float(end_r-begin_r)/256;
        delta_g = float(end_g-begin_g)/256;
        delta_b = float(end_b-begin_b)/256;
        for(j=0;j<256;j++){
            int set_r, set_g, set_b;
            set_r = begin_r + j * delta_r;
            set_g = begin_g + j * delta_g;
            set_b = begin_b + j * delta_b;
            colormap[j][0] = set_r;
            colormap[j][1] = set_g;
            colormap[j][2] = set_b;
            colorbar_img.setPixel(j,i,qRgb(set_r,set_g,set_b));
        }
    }
    displayIMG(ui->label_colorbar,colorbar_img);
}

void Widget::colorSegmentation(){
    int k = ui->horizontalSlider_ColorSeg_k->value();
    if(ui->radioButton_ColorSeg_planes_RGB->isChecked())
        kmean(k, oriImg.rgbPlane, oriImg.rgbPlane);
    else if(ui->radioButton_ColorSeg_planes_hsi->isChecked())
        kmean(k, oriImg.hsiPlane, oriImg.rgbPlane);
    else if(ui->radioButton_ColorSeg_planes_lab->isChecked())
        kmean(k, oriImg.labPlane, oriImg.rgbPlane);
}

void Widget::kmean(int k, Mat img, Mat rgb_Img){
    /* K-means:
     *      double cv::kmeans(
     *          cv::InputArray         data,       // one sample(float) per line.
     *          int                    k,          // k
     *          cv::InputOutputArray   bestLabels, // result of k-means
     *          cv::TermCriteria       criteria,   // end condition
     *          int                    attempts,
     *          int                    flags,
     *          cv::OutputArray        centers     // the centor point of result of k-means
     *      );
     */
    img.convertTo(img,CV_32FC3);
    rgb_Img.convertTo(rgb_Img,CV_32FC3);
    int row = img.rows;
    int col = img.cols;
    int size = row*col;
    /* Create data */
    Mat clusters(size, 1, CV_32SC1);
    Mat srcPoint(size, 1, CV_32FC3);
    Vec3f* srcPoint_p = (Vec3f*)srcPoint.data;
    Vec3f* src_p = (Vec3f*)img.data;
    int i;
    for(i=0;i<size;i++){
       *srcPoint_p = *src_p;
       srcPoint_p++;
       src_p++;
    }
    /* centor */
    Mat center(k,1,CV_32FC3);
    /* k-means */
    double compactness;
    compactness = kmeans(srcPoint, k, clusters,
       cvTermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 0.1), k,
       KMEANS_PP_CENTERS , center);
    int* clusters_p = (int*)clusters.data;
    Mat label(img.size(), CV_32SC1);
    int* label_p = (int*)label.data;
    //assign the clusters to Mat label
    for(i = 0;i < size; i++){
       *label_p = *clusters_p;
       label_p++;
       clusters_p++;
    }
    normalize(label,label,0,255,CV_MINMAX);
    /* Compute the avg color of one label */
    map<int,int> count; /* record the num of the label */
    map<int,Vec3f> avg; /* record the avg value of the label */
    /* First, record sum & count */
    int x,y;
    for (y=0;y<row;y++){
       const Vec3f* imgData = rgb_Img.ptr<Vec3f>(y);
       int* idx = label.ptr<int>(y);
       for(x=0;x<col;x++){
           avg[idx[x]] += imgData[x];
           count[idx[x]] ++;
       }
    }
    /* And then, compute avg value */
    for (i=0;i<size;i++){
        avg[i] /= count[i];
    }
    /* Convert oriImg to segment img */
    Mat resultImg(img.size(),CV_32FC3); /* store the result of img */
    for(y=0;y<row;y++){
        Vec3f* imgData = resultImg.ptr<Vec3f>(y);
        int* idx = label.ptr<int>(y);
        for (x=0;x<col;x++){
            int id = idx[x];
            imgData[x].val[0] = avg[id].val[0];
            imgData[x].val[1] = avg[id].val[1];
            imgData[x].val[2] = avg[id].val[2];
        }
    }
    normalize(resultImg,resultImg,0,1,CV_MINMAX);
    resultImg.convertTo(resultImg,CV_8UC3,255);
    proImg = resultImg.clone();
    displayIMG(ui->label_ProImg,Mat2QImage(resultImg));
}

Mat Widget::rgb2cmy(Mat rgb_img){
    Mat cmy_img(rgb_img.rows,rgb_img.cols,rgb_img.type());
    int r, g, b, c, m, y;
    int i, j;

    for(i=0;i<rgb_img.rows;i++){
        for(j=0;j<rgb_img.cols;j++){
            b = rgb_img.at<Vec3b>(i,j)[0];
            g = rgb_img.at<Vec3b>(i,j)[1];
            r = rgb_img.at<Vec3b>(i,j)[2];
            c = 255 - r;
            m = 255 - g;
            y = 255 - b;
            cmy_img.at<Vec3b>(i,j)[0] = y;
            cmy_img.at<Vec3b>(i,j)[1] = m;
            cmy_img.at<Vec3b>(i,j)[2] = c;
        }
    }
    return cmy_img;
}

Mat Widget::rgb2hsi(Mat rgb_img){
    Mat hsi_plane[3] = {
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
    };
    Mat hsi_img;
    float r, g, b, h, s, in;
    int i, j;

    for(i=0;i<rgb_img.rows;i++){
        for(j=0;j<rgb_img.cols;j++){
            b = rgb_img.at<Vec3b>(i,j)[0];
            g = rgb_img.at<Vec3b>(i,j)[1];
            r = rgb_img.at<Vec3b>(i,j)[2];
            in = (r + g + b)/3;
            s = 1 - 3*(MIN(MIN(r,g),b)/(r+g+b));
            if(s<0.00001) s=0;
            if(s>0.99999) s=1;
            if(r==g&&g==b) h = 0;
            else h = acos(0.5*((r-g)+(r-b))/sqrt((r-g)*(r-g)+(r-b)*(g-b)));
            h = b>g?(2*M_PI-h):h;
            hsi_plane[0].at<float>(i,j) = (h*180)/M_PI;
            hsi_plane[1].at<float>(i,j) = s;
            hsi_plane[2].at<float>(i,j) = in;
        }
    }
    for(i=0;i<3;i++){
        normalize(hsi_plane[i],hsi_plane[i],0,255,NORM_MINMAX,hsi_plane[i].type());
        hsi_plane[i].convertTo(hsi_plane[i], CV_8U);
    }
    merge(hsi_plane,3,hsi_img);
    return hsi_img;
}

Mat Widget::rgb2xyz(Mat rgb_img){
    Mat xyz_plane[3] = {
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F)
    };
    Mat xyz_img;
    float r, g, b, x, y, z;
    int i, j;

    for(i=0;i<rgb_img.rows;i++){
        for(j=0;j<rgb_img.cols;j++){
            b = float(rgb_img.at<Vec3b>(i,j)[0]);
            g = float(rgb_img.at<Vec3b>(i,j)[1]);
            r = float(rgb_img.at<Vec3b>(i,j)[2]);
            x = 0.412453*r + 0.357580*g + 0.180423*b;
            y = 0.212671*r + 0.715160*g + 0.072469*b;
            z = 0.019334*r + 0.119193*g + 0.950227*b;
            xyz_plane[0].at<float>(i,j) = x;
            xyz_plane[1].at<float>(i,j) = y;
            xyz_plane[2].at<float>(i,j) = z;
        }
    }
    for(i=0;i<3;i++){
        normalize(xyz_plane[i],xyz_plane[i],0,255,NORM_MINMAX,xyz_plane[i].type());
        xyz_plane[i].convertTo(xyz_plane[i], CV_8U);
    }
    merge(xyz_plane,3,xyz_img);
    return xyz_img;
}

Mat Widget::rgb2lab(Mat rgb_img){
    Mat xyz_img;
    Mat xyz_plane[3]{
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F)
    };
    float r, g, b, x, y, z, l_star, a_star, b_star, fofx, fofy, fofz;
    int i, j;

    for(i=0;i<rgb_img.rows;i++){
        for(j=0;j<rgb_img.cols;j++){
            b = float(rgb_img.at<Vec3b>(i,j)[0])/255;
            g = float(rgb_img.at<Vec3b>(i,j)[1])/255;
            r = float(rgb_img.at<Vec3b>(i,j)[2])/255;
            x = (0.412453*r + 0.357580*g + 0.180423*b)/0.95047;
            y = (0.212671*r + 0.715160*g + 0.072469*b)/1.0;
            z = (0.019334*r + 0.119193*g + 0.950227*b)/1.08883;
            fofx = x>0.008856?(pow(x,1.0/3.0)):(7.787*x+16.0/116.0);
            fofy = y>0.008856?(pow(y,1.0/3.0)):(7.787*y+16.0/116.0);
            fofz = z>0.008856?(pow(z,1.0/3.0)):(7.787*z+16.0/116.0);
            l_star = fofy>0.008856?(116*pow(y,1.0/3.0)-16):(903.3*y);
            a_star = 500*(fofx-fofy);
            b_star = 200*(fofy-fofz);
            xyz_plane[0].at<float>(i,j) = l_star;
            xyz_plane[1].at<float>(i,j) = a_star;
            xyz_plane[2].at<float>(i,j) = b_star;
//            cout << r << " " << g << " " << b << " " << x << " " << y << " " << z << " " << fofx << " " << fofy << " " << fofz << " " << l_star << " " << a_star << " " << b_star << endl;
        }
    }
    for(i=0;i<3;i++){
        normalize(xyz_plane[i],xyz_plane[i],0,255,NORM_MINMAX,xyz_plane[i].type());
        xyz_plane[i].convertTo(xyz_plane[i], CV_8U);
//        imshow(to_string(i),xyz_plane[i]);
    }
    merge(xyz_plane,3,xyz_img);
    return xyz_img;
}

Mat Widget::rgb2yuv(Mat rgb_img){
    Mat yuv_img;
    Mat yuv_plane[3]{
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F),
        Mat::zeros(rgb_img.rows,rgb_img.cols,CV_32F)
    };
    float r, g, b, y, u, v;
    int i, j;

    for(i=0;i<rgb_img.rows;i++){
        for(j=0;j<rgb_img.cols;j++){
            b = float(rgb_img.at<Vec3b>(i,j)[0]);
            g = float(rgb_img.at<Vec3b>(i,j)[1]);
            r = float(rgb_img.at<Vec3b>(i,j)[2]);
            y = ( 0.299 *r + 0.587 *g + 0.114 *b);
            u = (-0.169 *r - 0.331 *g + 0.5   *b + 128);
            v = ( 0.5   *r - 0.419 *g - 0.081 *b + 128);
            yuv_plane[0].at<float>(i,j) = y;
            yuv_plane[1].at<float>(i,j) = u;
            yuv_plane[2].at<float>(i,j) = v;
//            cout << r << " " << g << " " << b << " " << x << " " << y << " " << z << " " << fofx << " " << fofy << " " << fofz << " " << l_star << " " << a_star << " " << b_star << endl;
        }
    }
    for(i=0;i<3;i++){
        normalize(yuv_plane[i],yuv_plane[i],0,255,NORM_MINMAX,yuv_plane[i].type());
        yuv_plane[i].convertTo(yuv_plane[i], CV_8U);
//        imshow(to_string(i),yuv_plane[i]);
    }
    merge(yuv_plane,3,yuv_img);
    return yuv_img;
}

Mat Widget::hsi2rgb(Mat hsi_img){
    Mat rgb_img(hsi_img.rows,hsi_img.cols,hsi_img.type());
    float r, g, b, h, s, in;
    int i, j;

    for(i=0;i<hsi_img.rows;i++){
        for(j=0;j<hsi_img.cols;j++){
            h  = hsi_img.at<Vec3b>(i,j)[0];
            s  = float(hsi_img.at<Vec3b>(i,j)[1])/100;
            in = hsi_img.at<Vec3b>(i,j)[2];
            if(h>=0&&h<120){
                b = in * (1 - s);
                r = in * (1 + s*cos(h*M_PI/180)/cos((60-h)*M_PI/180));
                g = 3*in - (r + b);
            }else if(h>=120&&h<240){
                h = h - 120;
                r = in * (1 - s);
                g = in * (1 + s*cos(h*M_PI/180)/cos((60-h)*M_PI/180));
                b = 3*in - (r + g);
            }else{
                h = h - 240;
                g = in * (1 - s);
                b = in * (1 + s*cos(h*M_PI/180)/cos((60-h)*M_PI/180));
                r = 3*in - (g + b);
            }
            rgb_img.at<Vec3b>(i,j)[0] = b;
            rgb_img.at<Vec3b>(i,j)[1] = g;
            rgb_img.at<Vec3b>(i,j)[2] = r;
        }
    }
    return rgb_img;
}

void Widget::ui_config(){
    dispalyListOfImage("./img");
    ui->label_c1->setPixmap(QPixmap::fromImage(colorList(255,0,0)));
    ui->label_c2->setPixmap(QPixmap::fromImage(colorList(255,85,17)));
    ui->label_c3->setPixmap(QPixmap::fromImage(colorList(255,187,0)));
    ui->label_c4->setPixmap(QPixmap::fromImage(colorList(187,255,0)));
    ui->label_c5->setPixmap(QPixmap::fromImage(colorList(0,255,0)));
    ui->label_c6->setPixmap(QPixmap::fromImage(colorList(0,255,204)));
    ui->label_c7->setPixmap(QPixmap::fromImage(colorList(0,187,255)));
    ui->label_c8->setPixmap(QPixmap::fromImage(colorList(0,0,255)));
    ui->label_c9->setPixmap(QPixmap::fromImage(colorList(119,0,255)));
    ui->label_c10->setPixmap(QPixmap::fromImage(colorList(204,0,255)));
}

QImage Widget::colorList(int r, int g, int b){
    QImage img(50,50,QImage::Format_RGB32);
    int i,j;
    for(i=0;i<50;i++){
        for(j=0;j<50;j++){
            img.setPixel(j,i,qRgb(r,g,b));
        }
    }
    return img;
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
    oriImg.rgbPlane = imread(img_vec[d].path.toStdString(), 1);
    oriImg.cmyPlane = rgb2cmy(oriImg.rgbPlane);
    oriImg.hsiPlane = rgb2hsi(oriImg.rgbPlane);
    oriImg.xyzPlane = rgb2xyz(oriImg.rgbPlane);
    oriImg.labPlane = rgb2lab(oriImg.rgbPlane);
    oriImg.yuvPlane = rgb2yuv(oriImg.rgbPlane);
    splitAndDisplatPlane(ui->label_RGB_B,ui->label_RGB_G,ui->label_RGB_R,oriImg.rgbPlane);
    splitAndDisplatPlane(ui->label_CMY_Y,ui->label_CMY_M,ui->label_CMY_C,oriImg.cmyPlane);
    splitAndDisplatPlane(ui->label_HSI_H,ui->label_HSI_S,ui->label_HSI_I,oriImg.hsiPlane);
    splitAndDisplatPlane(ui->label_XYZ_x,ui->label_XYZ_y,ui->label_XYZ_z,oriImg.xyzPlane);
    splitAndDisplatPlane(ui->label_Lab_L,ui->label_Lab_A,ui->label_Lab_B,oriImg.labPlane);
    splitAndDisplatPlane(ui->label_YUV_Y,ui->label_YUV_U,ui->label_YUV_V,oriImg.yuvPlane);

    QImage oriImg_QIMG = Mat2QImage(oriImg.rgbPlane);
    displayIMG(ui->label_OriImg, oriImg_QIMG);

}

void Widget::splitAndDisplatPlane(QLabel* l1, QLabel* l2, QLabel* l3, Mat img){
    Mat plane[3];
    split(img,plane);
    int i;
    for(i=0;i<3;i++)
        normalize(plane[i],plane[i],0,255,NORM_MINMAX,img.type());
    displayIMG(l1,Mat2QImage(plane[0]));
    displayIMG(l2,Mat2QImage(plane[1]));
    displayIMG(l3,Mat2QImage(plane[2]));
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
