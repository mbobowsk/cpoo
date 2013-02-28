#include "controller.h"

//TODO remove
#include <QDebug>
#include <vector>
#include <algorithm>

Controller::Controller()
{
}

// Filtracja medianowa zwykła
QImage* Controller::median(QImage *oldImg) {
    if ( oldImg->isGrayscale() ) {
        qDebug() << "Grayscale";
        return NULL;
    }

    QImage* newImg = new QImage(oldImg->size(),oldImg->format());
    // sparametryzować
    int size = 3;

    for ( int x = 1; x != oldImg->width()-1; ++x ) {
        for ( int y = 1; y != oldImg->height()-1; ++y ) {
            std::vector<QRgb> values;
            // Okno analizy
            for ( int i = x-size/2; i <= x+size/2; ++i ) {
                for ( int j = y-size/2; j <= y+size/2; ++j ) {
                    values.push_back(oldImg->pixel(i,j));
                }
            }
            std::sort(values.begin(),values.end(),Controller::sortRgb);

            //QRgb value = oldImg->pixel(x,y);


            newImg->setPixel(x,y,values[values.size()/2]);
        }
    }
    return newImg;
}

// Adaptacyjna filtracja medianowa
QImage* Controller::adaptMedian(QImage *oldImg) {
    qDebug()<<"mediana adaptacyjna";
    return NULL;
}

// Funkcja określająca kolejność punktów przy sortowaniu
bool Controller::sortRgb(QRgb a, QRgb b) {
    int sumA = qRed(a)+qGreen(a)+qBlue(a);
    int sumB = qRed(b)+qGreen(b)+qBlue(b);
    return sumA < sumB;
}


