#include <iostream>
#include <assert.h>
#include <math.h>
#include <QImage>
using namespace std;

#define PI 3.14159265358979323846

int **log_filter(int filter_size, float sigma=1.4) {
    assert(filter_size%2==1);

    int **filter = new int*[filter_size];
    float d;

    d = 4.0*(filter_size+1)*(PI*pow(sigma, 4));
    for(int i=0; i<filter_size; ++i) {
        filter[i] = new int[filter_size];
        for(int j=0; j<filter_size; ++j) {
            float x, y;
            float t, log;

            x = float(i-int(filter_size/2));
            y = float(j-int(filter_size/2));

            t = -1.0*(pow(x, 2)+pow(y, 2))/(2*pow(sigma, 2));
            cout << x << " " << y << " " << t << " " << d << endl;
            log = -1.0/(PI*pow(sigma, 4))*(1.0+t)*exp(t);
            
            filter[i][j] = round(d*log);
        }
    }
    return filter;
}

int **convolution(QImage &img, int **filter, int filter_size) {
    int width, height;
    int **c_r;

    width = img.width();
    height = img.height();
    c_r = new int*[height];

    for(int i=0; i<height; ++i) {
        c_r[i] = new int[width];
        for(int j=0; j<width; ++j) {
            int pixel = 0;

            for(int k=filter_size-1; k>=0; --k) {
                int i_k;

                i_k = int(i-(k-int(filter_size/2)));
                for(int l=filter_size-1; l>=0; --l) {
                    int j_l;

                    j_l = int(j-(l-int(filter_size/2)));
                    if((i_k<0)||(i_k>=width)||(j_l<0)||(j_l>=height)) {
                        pixel+=0;
                    }
                    else {
                        pixel+=(filter[k][l]*qGray(img.pixel(j_l, i_k)));
                    }
                }
            }
            c_r[i][j] = pixel;
        }
    }
    return c_r;
}

int **zero_crossing(int **c_r, int width, int height, int threshold=0) {
    int **c_g;
    
    c_g = new int*[height];
    for(int i=0; i<height; ++i) {
        c_g[i] = new int[width];
        for(int j=0; j<width; ++j) {
            int count = 0;
            for(int k=-1; k<1; ++k) {
                for(int l=-1; l<1; ++l) {
                    int t_px, n_px;
                    int i_n_px, j_n_px;

                    i_n_px = i+k;
                    j_n_px = j+l;
                    t_px = c_r[i][j];
                    n_px = c_r[i_n_px][j_n_px];
                    
                    if((i_n_px<0)||i_n_px>=height) continue;
                    if((j_n_px<0)||j_n_px>=width) continue;
                    if((k==0)&&(l==0)) continue;
                    if((t_px*n_px<0)&&(abs(t_px-n_px)>threshold)) {
                        c_g[i][j] = 1;
                        goto end;
                    }
                }
            }
            end:;
        }
    }
    return c_g;
}

QImage int_array_to_QImage(int **array, int width, int height, int multiple=1) {
    QImage img(width, height, QImage::Format_RGB32);

    for (int i=0; i<height; ++i) {
        for (int j=0; j<width; ++j) {
            int pixel = array[i][j]*multiple;
            img.setPixel(j, i, qRgb(pixel, pixel, pixel));
        }
    }
    return img;
}

QImage edge_detection(QImage &img, int &filter_size, float sigma=1.4, int threshold=0) {
    int **filter, **c_r, **c_g;
    int width, height;
    QImage img_out;

    width = img.width();
    height = img.height();
    filter = log_filter(filter_size, sigma);
    c_r = convolution(img, filter, filter_size);
    c_g = zero_crossing(c_r, width, height, threshold);
    img_out = int_array_to_QImage(c_g, width, height, 255);
    return img_out;
}

int main() {
    QImage img("./test.jpg");
    int filter_size = 5;
    QImage img_log = edge_detection(img, filter_size, 1.4, 0);

    img_log.save("./test_log.png");
    return 0;
}