#include "controller.h"

//TODO remove
#include <QDebug>
#include <math.h>

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
    // Wysokość i szerokość obrazka
    int height = oldImg->height();
    int width = oldImg->width();
    // sparametryzować
    int size = 3;
    // Liczba pikseli na obwodzie nie brana pod uwagę
    // jak również połowa rozmiaru okna analizy
    int border = size/2;
    // Skopiowanie pikseli z granicy
    fillBorders(oldImg,newImg,border);

    for ( int x = border; x != width-border; ++x ) {
        for ( int y = border; y != height-border; ++y ) {
            // Okno analizy
            std::vector<QRgb> pixels;
            for ( int i = x-border; i <= x+border; ++i ) {
                for ( int j = y-border; j <= y+border; ++j ) {
                    pixels.push_back(oldImg->pixel(i,j));
                }
            }
            // Wartości sumy odległości od pozostałych pikseli
            std::vector<int> distance;
            for ( unsigned i = 0; i != pixels.size(); ++i )
                distance.push_back(countDst(pixels,i));
            // Wyszukiwanie indeksu najmniejszego elementu
            int lowIndex = 0;
            for ( unsigned i = 1; i != distance.size(); ++i ) {
                if ( distance[i] < distance[lowIndex] )
                    lowIndex = i;
            }
            // Zapis 'medianowego' piksela do nowego obrazka
            newImg->setPixel(x,y,pixels[lowIndex]);
        }
    }    
    return newImg;
}

// Adaptacyjna filtracja medianowa
QImage* Controller::adaptMedian(QImage *oldImg) {
    if ( oldImg->isGrayscale() ) {
        qDebug() << "Grayscale";
        return NULL;
    }

    QImage* newImg = new QImage(oldImg->size(),oldImg->format());
    // Wysokość i szerokość obrazka
    int height = oldImg->height();
    int width = oldImg->width();
    // Skopiowanie pikseli z granicy
    fillBorders(oldImg,newImg,1);

    for ( int x = border; x != width-border; ++x ) {
        for ( int y = border; y != height-border; ++y ) {
            // Okno analizy
            std::vector<QRgb> pixels;
            for ( int i = x-border; i <= x+border; ++i ) {
                for ( int j = y-border; j <= y+border; ++j ) {
                    pixels.push_back(oldImg->pixel(i,j));
                }
            }
            // Wartości sumy odległości od pozostałych pikseli
            std::vector<int> distance;
            for ( unsigned i = 0; i != pixels.size(); ++i )
                distance.push_back(countDst(pixels,i));
        }
    }
    return newImg;
}

int Controller::countDst(std::vector<unsigned>& pixels, int index) {
    int ret = 0;
    for ( int i = 0; i != pixels.size(); ++i ) {
        if ( i == index )
            continue;
        // Miara Euklidesowa
        ret += sqrt(pow(qRed(pixels[i])-qRed(pixels[index]),2) +
                    pow(qBlue(pixels[i])-qBlue(pixels[index]),2) +
                    pow(qGreen(pixels[i])-qGreen(pixels[index]),2));
    }
    return ret;
}

void Controller::fillBorders(QImage *oldImg, QImage *newImg, int border) {
    int height = oldImg->height();
    int width = oldImg->width();
    for ( int x = 0; x != border; ++x ) {
        for ( int y = 0; y !=height; ++y ) {
            newImg->setPixel(x,y,oldImg->pixel(x,y));
            newImg->setPixel(height-x-1,height-y-1,oldImg->pixel(height-x-1,width-y-1));
        }
    }
    for ( int y = 0; y != border; ++y ) {
        for ( int x = 0; x != width; ++x ) {
            newImg->setPixel(x,y,oldImg->pixel(x,y));
            newImg->setPixel(height-x-1,height-y-1,oldImg->pixel(height-x-1,width-y-1));
        }
    }
}
