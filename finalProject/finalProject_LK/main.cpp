#include "widget.h"
#include <QApplication>

void onMouse(int Event,int x,int y,int flags,void* param);
Point mouse(-1,-1);
int choosen_d = 20;
int tracking_region = 85;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    VideoCapture cap(0);

    w.show();
    Mat frame, preframe, frame_grey, preframe_grey, trackingObject, imgC, path;
    Point trackingObject_LeftTop, trackingObject_RightBottom;
    vector<Point2f> precorners, corners;
    int i;
    bool trackingMode;
    vector<uchar> features_found;
    trackingMode = 0;

    namedWindow("webCAM",CV_WINDOW_AUTOSIZE);
//    preframe = imread("./IMG/preframe.jpg",1);
//    frame = imread("./IMG/frame.jpg",1);
//    imshow("preframe",preframe);
//    imshow("frame",frame);
    cap >> preframe;
    path.create(preframe.size(),preframe.type());
    for(;;){
        cap >> frame;
        cap >> imgC;
        imshow("webCAM",frame);
        if(mouse.x==-1&mouse.y==-1){
            setMouseCallback("webCAM",onMouse,NULL);
            trackingMode = 1;
        }
        if(trackingMode){
            trackingObject_LeftTop = mouse-Point(choosen_d,choosen_d);
            trackingObject_RightBottom = mouse+Point(choosen_d,choosen_d);
            cvtColor(preframe,preframe_grey,CV_RGB2GRAY);
            cvtColor(frame,frame_grey,CV_RGB2GRAY);
            goodFeaturesToTrack(preframe_grey,precorners,100,0.01,10,Mat());
            cornerSubPix(preframe_grey,precorners,Size(30,30),Size(-1,-1),TermCriteria(TermCriteria::MAX_ITER,20,0.03));
            calcOpticalFlowPyrLK(preframe_grey,frame_grey,precorners,corners,features_found,cv::noArray(),Size(61,61),5,TermCriteria(TermCriteria::MAX_ITER,20,0.03));

            for(i=0;i<corners.size();i++){
                if(corners[i].inside(Rect(trackingObject_LeftTop,trackingObject_RightBottom))){
                    line(imgC, precorners[i], corners[i], Scalar(0,0,255), 2, LINE_AA);
                    circle(path,corners[i],2,Scalar(0,0,255),10,4,0);
                    mouse = corners[i];
                }
            }
            imshow("path",path);
            imshow("webCAM",imgC);
            preframe = frame.clone();
            precorners = corners;
        }
        if(waitKey(30) >= 0) break;
    }
    return a.exec();
}

void onMouse(int Event,int x,int y,int flags,void* param){
    if(Event==CV_EVENT_LBUTTONDOWN){
        mouse.x = x;
        mouse.y = y;
    }
}
