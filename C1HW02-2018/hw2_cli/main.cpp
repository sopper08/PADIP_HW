#include <iostream>
#include <assert.h>
#include <math.h>
#include <string>
#include <QImage>

using namespace std;

QImage enlarge(QImage &img, int scaled) {
    int width, height;
    QImage s_img;

    width = img.width();
    height = img.height();
    s_img = QImage(width*scaled, height*scaled, QImage::Format_Grayscale8);

    for (int v=0; v<s_img.height(); ++v) {
        for (int u=0; u<s_img.width(); ++u) {
            int x, y, pixel;
            float a, b, c, d;

            x = int(u/scaled); y = int(v/scaled);
            a = float(u)/float(scaled)-x; c = 1-a;
            b = float(v)/float(scaled)-y; d = 1-b;

            if(((x+1)==width)||((y+1)==height)) {
                pixel = 0;
            }
            else {
                pixel = c*d*qGray(img.pixel(  x,   y)) +
                        a*d*qGray(img.pixel(x+1,   y)) +
                        c*b*qGray(img.pixel(  x, y+1)) +
                        a*b*qGray(img.pixel(x+1, y+1));
            }
            s_img.setPixel(u, v, qRgb(pixel, pixel, pixel));
        }
    }
    return s_img;
}

QImage histogram_equalization(QImage &img) {
    int width, height, pixel_sum;
    int gray_array[256] = {0};
    int accumulate_gray_array[256] = {0};
    int pixel_table[256] = {0};
    QImage he_img;

    width = img.width();
    height = img.height();
    he_img = QImage(width, height, QImage::Format_Grayscale8);

    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            int pixel;
            pixel = qGray(img.pixel(j, i));
            ++gray_array[pixel];
        }
    }

    pixel_sum = width*height;
    accumulate_gray_array[0] = gray_array[0];
    pixel_table[0] = round(255.0*float(accumulate_gray_array[0])/pixel_sum);
    for(int i=1; i<256; ++i) {
        accumulate_gray_array[i] = accumulate_gray_array[i-1]+gray_array[i];
        pixel_table[i] = round(255.0*float(accumulate_gray_array[i])/pixel_sum);
    }

    for(int i=0; i<height; ++i) {
        for(int j=0; j<width; ++j) {
            int pixel;
            pixel = qGray(img.pixel(j, i));
            pixel = pixel_table[pixel];
            // cout << pixel << ": " << pixel_table[pixel] << endl;
            he_img.setPixel(j, i, qRgb(pixel, pixel, pixel));
        }
    }
    return he_img;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " enlarge <image_file> <ratio>"<< endl;
        cout << "Usage: " << argv[0] << " he <image_file>"<< endl;
        return 1;
    }
    
    string cmd(argv[1]);
    QImage img(argv[2]);
    QImage r_img;

    if (cmd.compare("enlarge") == 0) {
        if (argc < 4) {
            cout << "Usage: " << argv[0] << " enlarge <image_file> <ratio>"<< endl;
            return 1;
        }
        int scaled = atoi(argv[3]);
        r_img = enlarge(img, scaled);
    }
    else if (cmd.compare("he") == 0) {
        r_img = histogram_equalization(img);
    }
    else {
        cout << "Usage: " << argv[0] << " enlarge <image_file> <ratio>"<< endl;
        cout << "Usage: " << argv[0] << " he <image_file>"<< endl;
        return 1;
    }

    r_img.save("result.png");

    return 0;
}