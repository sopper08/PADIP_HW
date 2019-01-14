#include "widget.h"
#include <QApplication>

void onMouse(int Event,int x,int y,int flags,void* param);
Point mouse(100,100);
int choosen_d = 30;
int tracking_region = 85;

int main(int argc, char *argv[])
{
    Point preMouse(100,100), matchPosition, pre_matchPosition;
    bool trackingMode;
    int storeNum;
    storeNum = 0;
    QApplication a(argc, argv);
    Widget w;

    VideoCapture cap(0);
    namedWindow("webCAM",CV_WINDOW_AUTOSIZE);
    Mat frame, templateIMG, resultIMG, trackIMG, path;
    cap >> frame;
    path.create(frame.size(),frame.type());
    for(;;){
        /* Frame: Capture image from camera. */
        cap >> frame;
        setMouseCallback("webCAM",onMouse,NULL);
        if(mouse.x!=preMouse.x&&mouse.y!=preMouse.y){
            /* Cut the template image. */
            Point leftTop,rightBottom;
            leftTop = mouse-Point(choosen_d,choosen_d);
            rightBottom = mouse+Point(choosen_d,choosen_d);
            templateIMG = frame(Rect(leftTop,rightBottom)).clone();
            rectangle(frame,leftTop,rightBottom,Scalar(0,0,255),2);
            imshow("templateIMG", templateIMG);
            preMouse = mouse;
            pre_matchPosition = mouse;
            trackingMode = true;
            string str = "./IMG/path_" + to_string(storeNum) + ".jpg";
            imwrite(str,path);
            path = Mat::zeros(path.size(),path.type());
            storeNum++;
        }
        /* Tracking mode */
        if(trackingMode){
            /* Selecting track region by tracking_region. */
            Point trackRegion_LeftTop, trackRegion_RightBottom;
            trackRegion_LeftTop = pre_matchPosition-Point(tracking_region,tracking_region);
            trackRegion_RightBottom = pre_matchPosition+Point(tracking_region,tracking_region);
            trackRegion_LeftTop.x = trackRegion_LeftTop.x<0?0:trackRegion_LeftTop.x;
            trackRegion_LeftTop.y = trackRegion_LeftTop.y<0?0:trackRegion_LeftTop.y;
            trackRegion_RightBottom.x = trackRegion_RightBottom.x>=frame.cols?frame.cols-1:trackRegion_RightBottom.x;
            trackRegion_RightBottom.y = trackRegion_RightBottom.y>=frame.rows?frame.rows-1:trackRegion_RightBottom.y;
            trackIMG = frame(Rect(trackRegion_LeftTop,trackRegion_RightBottom)).clone();
            resultIMG.create(trackIMG.rows-templateIMG.rows+1,trackIMG.cols-templateIMG.cols+1,CV_32FC1);
            matchTemplate(trackIMG,templateIMG,resultIMG,CV_TM_SQDIFF);
            minMaxLoc(resultIMG, 0, 0, &matchPosition, 0);
            matchPosition+=trackRegion_LeftTop;
            pre_matchPosition = matchPosition;
            normalize(resultIMG,resultIMG,0,1,NORM_MINMAX);
            circle(frame,matchPosition,2,Scalar(0,0,255),10,4,0);
            circle(path,matchPosition,2,Scalar(0,0,255),10,4,0);
            imshow("corre",resultIMG);
            imshow("path",path);
        }

        imshow("webCAM", frame);

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
