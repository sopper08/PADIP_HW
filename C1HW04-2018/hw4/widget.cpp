#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui_config();
    connect(ui->pushButton_ChooseFolder,SIGNAL(clicked()),this,SLOT(choose_folder()));
//    connect(ui->pushButton_Clear,SIGNAL(clicked()),ui->listWidget_ImageList,SLOT(clear()));
    connect(ui->listWidget_ImageList,SIGNAL(currentRowChanged(int)),this,SLOT(displayOriIMG(int)));
    connect(ui->pushButton_Execute,SIGNAL(clicked()),this,SLOT(execute()));
    connect(ui->horizontalSlider_Func_LP_ID_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_LP_ID_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_LP_Bu_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_LP_Bu_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_LP_Bu_N , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_LP_Bu_N , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_LP_Ga_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_LP_Ga_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_HP_ID_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_HP_ID_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_HP_Bu_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_HP_Bu_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_HP_Bu_N , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_HP_Bu_N , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_HP_Ga_D0, SIGNAL(valueChanged(int)), ui->lcdNumber_Func_HP_Ga_D0, SLOT(display(int)));
    connect(ui->horizontalSlider_Func_Homo_RH , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_Homo_RH , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_Homo_RL , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_Homo_RL , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_Homo_C  , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_Homo_C  , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_Homo_D0 , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_Homo_D0 , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_CreMBImg_A , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_CreMBImg_A , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_CreMBImg_B , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_CreMBImg_B , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_RemMBImg_IF_A , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_RemMBImg_IF_A , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_RemMBImg_IF_B , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_RemMBImg_IF_B , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_RemMBImg_WF_A , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_RemMBImg_WF_A , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_RemMBImg_WF_B , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_RemMBImg_WF_B , SLOT(display(int)));
    connect(ui->horizontalSlider_Func_RemMBImg_WF_K , SIGNAL(valueChanged(int)), ui->lcdNumber_Func_RemMBImg_WF_K , SLOT(display(int)));
    connect(ui->pushButton_ProImg_store, SIGNAL(clicked()), this, SLOT(storeProcessedImg()));
    connect(ui->pushButton_IF, SIGNAL(clicked()), this, SLOT(oriIFFT()));
    connect(ui->pushButton_ADDN, SIGNAL(clicked()), this, SLOT(addNoice()));
}

void Widget::oriIFFT(){
    Mat img_F = OriImg.img_F.clone();
    processedImg.img_F = img_F.clone();
    Mat img;
    idft(img_F,img,DFT_REAL_OUTPUT);
    normalize(img,img,0,1,NORM_MINMAX,img.type());
    img.convertTo(img, CV_8U, 255);
    int oriCols = OriImg.img_S.cols;
    int oriRows = OriImg.img_S.rows;
    processedImg.img_S = Mat(img, Rect(0,0,oriCols,oriRows));
    /* Spectrum and Phase Angle */
    Mat img_F_euler = transtoEuler(img_F);
    processedImg.img_F_euler = img_F_euler;
    displayProcessedImg(&processedImg);
}

void Widget::addNoice(){
    Mat img_S = Mat_<float>(OriImg.img_S);
    int cols = img_S.cols;
    int rows = img_S.rows;
    Mat white_mat;
    white_mat.create(img_S.size(), CV_32F);
    randn(white_mat,0,2);
//    imshow("123", white_mat);
    img_S+=white_mat;
    imshow("123", OriImg.img_S);

}

void Widget::storeProcessedImg(){
    Mat img = processedImg.img_S;
    imwrite("./processedImg/processedImg.jpg", img);
}

void Widget::execute(){
    int i = ui->tabWidget_Func->currentIndex();
    switch (i) {
        case 0:
//            cout << "level1: " << 0 << endl;
            break;
        /* LP */
        case 1:{
            cout << "level1: " << 1 << endl;
            int j = ui->tabWidget_Func_LP->currentIndex();
            switch (j) {
                /* ILPF */
                case 0:{
                    int d0 = ui->horizontalSlider_Func_LP_ID_D0->value();
                    ILPF(OriImg, &processedImg, d0, true);
                    displayProcessedImg(&processedImg);
                    break;
                }
                /* BLPF */
                case 1:{
                    int d0 = ui->horizontalSlider_Func_LP_Bu_D0->value();
                    int n = ui->horizontalSlider_Func_LP_Bu_N->value();
                    BLPF(OriImg, &processedImg, d0, n, true);
                    displayProcessedImg(&processedImg);
                    break;
                }
                /* GLPF */
                case 2:{
                    int d0 = ui->horizontalSlider_Func_LP_Ga_D0->value();
                    GLPF(OriImg, &processedImg, d0, true);
                    displayProcessedImg(&processedImg);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        /* HP */
        case 2:{
            int j = ui->tabWidget_Func_HP->currentIndex();
            switch (j) {
                /* IHPF */
                case 0:{
                    cout << "hjahah" << endl;
                    int d0 = ui->horizontalSlider_Func_HP_ID_D0->value();
                    ILPF(OriImg, &processedImg, d0, false);
                    displayProcessedImg(&processedImg);
                    break;
                }
                /* BHPF */
                case 1:{
                    int d0 = ui->horizontalSlider_Func_HP_Bu_D0->value();
                    int n = ui->horizontalSlider_Func_HP_Bu_N->value();
                    BLPF(OriImg, &processedImg, d0, n, false);
                    displayProcessedImg(&processedImg);
                    break;
                }
                /* GHPF */
                case 2:{
                    int d0 = ui->horizontalSlider_Func_HP_Ga_D0->value();
                    GLPF(OriImg, &processedImg, d0, false);
                    displayProcessedImg(&processedImg);
                    break;
                }
                default:
                    break;
                }
            break;
        }
        /* HOMO */
        case 3:{
            int r_H = ui->horizontalSlider_Func_Homo_RH->value();
            int r_L = ui->horizontalSlider_Func_Homo_RL->value();
            int c   = ui->horizontalSlider_Func_Homo_C->value();
            int d0 = ui->horizontalSlider_Func_Homo_D0->value();
            HOMOF(OriImg, &processedImg, r_H, r_L, c, d0);
            displayProcessedImg(&processedImg);
            break;
        }
        /* Motion Blurred */
        case 4:{
            int a_100 = ui->horizontalSlider_Func_CreMBImg_A->value();
            int b_100 = ui->horizontalSlider_Func_CreMBImg_B->value();
            createMotionBImage(OriImg, &processedImg, a_100, b_100);
            displayProcessedImg(&processedImg);
            break;
        }
        case 5:{
            int j = ui->tabWidget_Func_RemMBImg->currentIndex();
            switch (j) {
            case 0:{
                int a_100 = ui->horizontalSlider_Func_RemMBImg_IF_A->value();
                int b_100 = ui->horizontalSlider_Func_RemMBImg_IF_B->value();
                inverseF(OriImg, &processedImg, a_100, b_100);
                displayProcessedImg(&processedImg);
                break;
            }
            case 1:{
                int a_100 = ui->horizontalSlider_Func_RemMBImg_WF_A->value();
                int b_100 = ui->horizontalSlider_Func_RemMBImg_WF_B->value();
                int k_100 = ui->horizontalSlider_Func_RemMBImg_WF_K->value();
                wienerF(OriImg, &processedImg, a_100, b_100, k_100);
                displayProcessedImg(&processedImg);
                break;
            }
            default:
                break;
            }
            break;
        }
        default:
            break;
    }

}

void Widget::displayProcessedImg(imgSandF* imgSF){
    displayIMG(ui->label_ProImg, Mat2QImage(imgSF->img_S));
    Mat plane[2];
    split(imgSF->img_F_euler, plane);
    displayIMG(ui->label_ProImgF_S, Mat2QImage(shiftTheFPlane(plane[0])));
    displayIMG(ui->label_ProImgF_PA, Mat2QImage(shiftTheFPlane(plane[1])));
}

void Widget::h_uiMULf_uv(Mat h_uv, Mat f_uv, imgSandF* g, int oriCols, int oriRows){
    /* G(u,v) = F(u,v)H(u,v) */
    Mat plane[2];
    split(f_uv,plane);
    plane[0] = plane[0].mul(h_uv);
    plane[1] = plane[1].mul(h_uv);
    merge(plane, 2, f_uv);
    g->img_F = f_uv;
    /* g(x,y) = F^-1{G(u,v)} */
    Mat img;
    idft(f_uv,img,DFT_REAL_OUTPUT);
    normalize(img,img,0,1,NORM_MINMAX,img.type());
    img.convertTo(img, CV_8U, 255);
    g->img_S = Mat(img, Rect(0,0,oriCols,oriRows));
    /* Spectrum and Phase Angle */
    Mat img_F_euler = transtoEuler(f_uv);
    g->img_F_euler = img_F_euler;
}

void Widget::ILPF(imgSandF oriImg, imgSandF* g, int d0, bool lpORhp){
    Mat img_F = oriImg.img_F.clone();
    /* Build a H(u, v) */
    Mat h_uv = Mat::zeros(img_F.size(), CV_32F);
    int cols = img_F.cols;
    int rows = img_F.rows;
    circle(h_uv, Point(0,0), d0, Scalar(1), -1, 8);
    circle(h_uv, Point(cols,0), d0, Scalar(1), -1, 8);
    circle(h_uv, Point(0,rows), d0, Scalar(1), -1, 8);
    circle(h_uv, Point(cols,rows), d0, Scalar(1), -1, 8);
    int oriCols = oriImg.img_S.cols;
    int oriRows = oriImg.img_S.rows;
    if(!lpORhp) h_uv = Mat::ones(h_uv.rows, h_uv.cols, h_uv.type()) - h_uv;
    h_uiMULf_uv(h_uv, img_F, g, oriCols, oriRows);

}

void Widget::BLPF(imgSandF oriImg, imgSandF* g, int d0, int n, bool lpORhp){
//    cout << "t" << endl;
    Mat img_F = oriImg.img_F.clone();
    Mat h_uv = Mat::zeros(img_F.size(), CV_32F);
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            float d_uv = sqrt(pow(i-cols/2,2)+pow(j-rows/2,2));
            h_uv.at<float>(i,j) = 1/(1+pow(d_uv/d0,2*n));
        }
    }
    h_uv = shiftTheFPlane(h_uv);
    int oriCols = oriImg.img_S.cols;
    int oriRows = oriImg.img_S.rows;
    if(!lpORhp) h_uv = Mat::ones(h_uv.rows, h_uv.cols, h_uv.type()) - h_uv;
    h_uiMULf_uv(h_uv, img_F, g, oriCols, oriRows);
}

void Widget::GLPF(imgSandF oriImg, imgSandF* g, int d0, bool lpORhp){
    Mat img_F = oriImg.img_F.clone();
    Mat h_uv = Mat::zeros(img_F.size(), CV_32F);
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            float d_uv = sqrt(pow(i-cols/2,2)+pow(j-rows/2,2));
            h_uv.at<float>(i,j) = exp(-pow(d_uv,2)/2/pow(d0,2));
        }
    }
    h_uv = shiftTheFPlane(h_uv);
    int oriCols = oriImg.img_S.cols;
    int oriRows = oriImg.img_S.rows;
    if(!lpORhp) h_uv = Mat::ones(h_uv.rows, h_uv.cols, h_uv.type()) - h_uv;
    h_uiMULf_uv(h_uv, img_F, g, oriCols, oriRows);
}

void Widget::HOMOF(imgSandF oriImg, imgSandF* g, int r_H, int r_L, int c, int d0){
    cout << r_H << " "<< r_L << " "<< c << " " << d0 << endl;
    double r_L_100 = double(r_L)/100;
    /* ln(1+f(x,y)) */
    Mat img_S = oriImg.img_S.clone();
    img_S.convertTo(img_S, CV_32F);
    img_S += Scalar::all(1);
    log(img_S, img_S);
    /* M(u,v) = F{ln(1+f(x,y))} */
    Mat img_F = imageFFT(img_S);
    /* H(u,v) */
    Mat h_uv = Mat::zeros(img_F.size(), CV_32F);
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            float d_uv = sqrt(pow(j-cols/2,2)+pow(i-rows/2,2));
            h_uv.at<float>(i,j) = (r_H-r_L_100)*(1-exp(-c*(pow(d_uv,2)/pow(d0,2))))+r_L_100;
        }
    }
    h_uv = shiftTheFPlane(h_uv);
    int oriCols = oriImg.img_S.cols;
    int oriRows = oriImg.img_S.rows;
    /* J(u,v) = H(u,v)M(u,v) */
    h_uiMULf_uv(h_uv, img_F, g, oriCols, oriRows);
    /* F^-1{J(u,v)} = j(x,y) */
    /* g(x,y) = exp(j(x,y))-1 */
    Mat imgs;
    Mat imgf = g->img_F.clone();
    idft(imgf,imgs,DFT_REAL_OUTPUT);
    normalize(imgs,imgs,0,1,NORM_MINMAX,imgs.type());
    exp(imgs,imgs);
    normalize(imgs,imgs,0,1,NORM_MINMAX,imgs.type());
    imgs.convertTo(imgs, CV_8U, 255);
    g->img_S = Mat(imgs, Rect(0,0,oriCols,oriRows));
}

void Widget::createMotionBImage(imgSandF oriImg, imgSandF* g, int a_100, int b_100){
    Mat img_F = oriImg.img_F.clone();
    /* H(u,v) */
    float a = float(a_100)/100;
    float b = float(b_100)/100;
    float t = 1;
    Mat h_uv_plane[2] = {Mat::zeros(img_F.size(), CV_32F), Mat::zeros(img_F.size(), CV_32F)};
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            /* u:i-rows/2, v:j-cols/2 */
            int u = i-rows/2;
            int v = j-cols/2;
            float uaADDub = M_PI*(u*a+v*b);
            h_uv_plane[0].at<float>(i,j) = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*cos(-uaADDub));
            h_uv_plane[1].at<float>(i,j) = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*sin(-uaADDub));
        }
    }
    h_uv_plane[0] = shiftTheFPlane(h_uv_plane[0]);
    h_uv_plane[1] = shiftTheFPlane(h_uv_plane[1]);
    Mat h_uv;
    merge(h_uv_plane,2,h_uv);
    mulSpectrums(img_F,h_uv,img_F,0,false);
    g->img_F = img_F.clone();
    g->img_F_euler = transtoEuler(img_F);
    idft(img_F,img_F,DFT_REAL_OUTPUT);
    normalize(img_F,img_F,0,1,NORM_MINMAX,img_F.type());
    img_F.convertTo(img_F, CV_8U, 255);
    g->img_S = img_F;
}

void Widget::inverseF(imgSandF oriImg, imgSandF* g, int a_100, int b_100){
    Mat img_F = oriImg.img_F.clone();
    /* H(u,v) */
    float a = float(a_100)/100;
    float b = float(b_100)/100;
    float t = 1;
    Mat h_uv_plane[2] = {Mat::zeros(img_F.size(), CV_32F), Mat::zeros(img_F.size(), CV_32F)};
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            /* u:i-rows/2, v:j-cols/2 */
            int u = i-rows/2;
            int v = j-cols/2;
            float uaADDub = M_PI*(u*a+v*b);
            float a = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*cos(-uaADDub));
            float b = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*sin(-uaADDub));
            h_uv_plane[0].at<float>(i,j) = a/(a*a+b*b)*1000;
            h_uv_plane[1].at<float>(i,j) = -b/(a*a+b*b)*1000;
        }
    }
    Mat f_uv[2];
    split(img_F,f_uv);
    h_uv_plane[0] = shiftTheFPlane(h_uv_plane[0]);
    h_uv_plane[1] = shiftTheFPlane(h_uv_plane[1]);
    Mat h_uv;
    merge(h_uv_plane,2,h_uv);
    mulSpectrums(img_F,h_uv,img_F,0,false);
    g->img_F = img_F.clone();
    g->img_F_euler = transtoEuler(img_F);
    idft(img_F,img_F,DFT_REAL_OUTPUT);
    normalize(img_F,img_F,0,1,NORM_MINMAX,img_F.type());
    img_F.convertTo(img_F, CV_8U, 255);
    g->img_S = img_F;
}

void Widget::wienerF(imgSandF oriImg, imgSandF* g, int a_100, int b_100, int k_100){
    Mat img_F = oriImg.img_F.clone();
    /* H(u,v) */
    float a = float(a_100)/100;
    float b = float(b_100)/100;
    float t = 1;
    float k = float(k_100)/10000;
    Mat h_uv_plane[2] = {Mat::zeros(img_F.size(), CV_32F), Mat::zeros(img_F.size(), CV_32F)};
    int cols = img_F.cols;
    int rows = img_F.rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            /* u:i-rows/2, v:j-cols/2 */
            int u = i-rows/2;
            int v = j-cols/2;
            float uaADDub = M_PI*(u*a+v*b);
            float a = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*cos(-uaADDub));
            float b = (uaADDub==0?1:(sin(uaADDub)/uaADDub)*t*sin(-uaADDub));
            h_uv_plane[0].at<float>(i,j) = a/(a*a+b*b+k)*1000;
            h_uv_plane[1].at<float>(i,j) = -b/(a*a+b*b+k)*1000;
        }
    }
    Mat f_uv[2];
    split(img_F,f_uv);
    h_uv_plane[0] = shiftTheFPlane(h_uv_plane[0]);
    h_uv_plane[1] = shiftTheFPlane(h_uv_plane[1]);
    Mat h_uv;
    merge(h_uv_plane,2,h_uv);
    mulSpectrums(img_F,h_uv,img_F,0,false);
    g->img_F = img_F.clone();
    g->img_F_euler = transtoEuler(img_F);
    idft(img_F,img_F,DFT_REAL_OUTPUT);
    normalize(img_F,img_F,0,1,NORM_MINMAX,img_F.type());
    img_F.convertTo(img_F, CV_8U, 255);
    g->img_S = img_F;
}

void Widget::ui_config(){
    dispalyListOfImage("./img");
}

void Widget::choose_folder(){
    img_vec.clear();
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
    result.create(2*rows, 2*cols, img_F_euler.type());
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
