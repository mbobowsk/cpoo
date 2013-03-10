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
            //          qDebug()<<"Low index"<<lowIndex;
            //          qDebug()<<"Low value"<<pixels[lowIndex];
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
    // sparametryzować
    int windowSize = 3;
    int maxWindowSize = 11;

    for ( int x = 0; x < width; ++x ) {
        for ( int y = 0; y < height; ++y ) {
            newImg->setPixel(x, y, adaptivePixel(oldImg, x, y, windowSize, maxWindowSize));
        }
    }
    return newImg;
}

QRgb Controller::adaptivePixel(QImage *original, int x, int y, int windowSize, int maxWindowSize){
    // Okno analizy
    std::list<QRgb> pixels;
    for ( int i = x-(windowSize/2); i <= x+(windowSize/2); ++i ) {
        for ( int j = y-(windowSize/2); j <= y+(windowSize/2); ++j ) {
            if (i < 0 || i == original->width() || y < 0 || y == original->height())
                continue;
            pixels.push_back(original->pixel(i,j));
        }
    }
    // Szukaj min / max / median
    QRgb fmin, fmed, fmax, forig;
    pixels.sort(adaptiveComparator);
    std::list<QRgb>::iterator it = pixels.begin();
    fmin = *it;
    std::advance(it, (pixels.size()/2 + 1));
    fmed = *it;
    std::advance(it, pixels.size());
    fmax = *it;

    forig = original->pixel(x, y);

    // Pierwszy warunek - czy mediana jest różna od skrajności
    if ((qRed(fmin) + qBlue(fmin) + qGreen(fmin))/3 < (qRed(fmed) + qBlue(fmed) + qGreen(fmed))/3 && (qRed(fmed) + qBlue(fmed) + qGreen(fmed))/3 < (qRed(fmax) + qBlue(fmax) + qGreen(fmax))/3){
        // Drugi warunek - czy oryginalny jest różny od skrajności
        if((qRed(fmin) + qBlue(fmin) + qGreen(fmin))/3 < (qRed(forig) + qBlue(forig) + qGreen(forig))/3 && (qRed(forig) + qBlue(forig) + qGreen(forig))/3 < (qRed(fmax) + qBlue(fmax) + qGreen(fmax))/3){
            return forig;
        }
        else
        {
            return fmed;
        }
    }
    else
    {
        // Sprawdź, czy nowe okno analizy nie będzie za duże
        if ((windowSize + 2) < maxWindowSize){
            // Uruchom rekurencyjnie z większym oknem analizy
            return adaptivePixel(original, x, y, windowSize+2, maxWindowSize);
        }
        else
        {
            return fmed;
        }
    }
}

bool Controller::adaptiveComparator(const QRgb first, const QRgb second){
    int firstGray = (qRed(first) + qBlue(first) + qGreen(first))/3;
    int secondGray = (qRed(second) + qBlue(second) + qGreen(second))/3;
    return (firstGray < secondGray);
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

// TODO remove, not used
double Controller::countLength(QRgb pixel) {

    return sqrt(pow(qRed(pixel)-qRed(pixel),2) +
                pow(qBlue(pixel)-qBlue(pixel),2) +
                pow(qGreen(pixel)-qGreen(pixel),2));

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
