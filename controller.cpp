#include "controller.h"

//TODO remove
#include <QDebug>
#include <math.h>

Controller::Controller()
{
}

// Filtracja medianowa zwykła
QImage* Controller::median(QImage *oldImg, int windowSize, double parameter) {
    if ( oldImg->isGrayscale() ) {
        QImage tmp = oldImg->convertToFormat(QImage::Format_RGB32);
        oldImg = &tmp;
    }

    QImage* newImg = new QImage(oldImg->size(),oldImg->format());
    // Wysokość i szerokość obrazka
    int height = oldImg->height();
    int width = oldImg->width();
    // sparametryzować
    int size = windowSize;
    int border = size/2;

    for ( int x = 0; x != width; ++x ) {
        for ( int y = 0; y != height; ++y ) {
            // Okno analizy
            std::vector<QRgb> pixels;
            for ( int i = x-border; i <= x+border; ++i ) {
                for ( int j = y-border; j <= y+border; ++j ) {
                    if ( i < 0 || j < 0 || i >= width || j >= height )
                        continue;
                    pixels.push_back(oldImg->pixel(i,j));
                }
            }
            // Wartości sumy odległości od pozostałych pikseli
            std::vector<int> distance;
            for ( unsigned i = 0; i != pixels.size(); ++i )
                distance.push_back(countDst(pixels,i,parameter));
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
QImage* Controller::adaptMedian(QImage *oldImg, int windowSize) {
    if ( oldImg->isGrayscale() ) {
        QImage tmp = oldImg->convertToFormat(QImage::Format_RGB32);
        oldImg = &tmp;
    }

    QImage* newImg = new QImage(oldImg->size(),oldImg->format());
    // Wysokość i szerokość obrazka
    int height = oldImg->height();
    int width = oldImg->width();
    // sparametryzować
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
            if (i < 0 || i >= original->width() || j < 0 || j >= original->height()){
                continue;
            }
            pixels.push_back(original->pixel(i,j));
        }
    }
    // Szukaj min / max / median
    QRgb fmin, fmed, fmax, forig;
    pixels.sort(adaptiveComparator);

    std::list<QRgb>::iterator it = pixels.begin();
    fmin = *it;

    for (int i = 0; it != pixels.end(); it++, i++ ) {
        if (i == (pixels.size()/2)){
            fmed = *it;
            break;
        }
    }

    it = pixels.end();
    it--;
    fmax = *it;

    forig = original->pixel(x, y);

    // Pierwszy warunek - czy mediana jest różna od skrajności
    if (countLength(fmin) < countLength(fmed) && countLength(fmed) < countLength(fmax)){
        // Drugi warunek - czy oryginalny jest różny od skrajności
        if(countLength(fmin) < countLength(forig) && countLength(forig) < countLength(fmax)){
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
    double firstLength = countLength(first);
    double secondLength = countLength(second);
    return (firstLength < secondLength);
}

int Controller::countDst(std::vector<unsigned>& pixels, int index, double p) {
    // Odległość wg miary euklidesowej
    int distance = 0;
    for ( int i = 0; i != pixels.size(); ++i ) {
        if ( i == index )
            continue;
        // Miara Euklidesowa
        distance += sqrt(pow(qRed(pixels[i])-qRed(pixels[index]),2) +
                    pow(qBlue(pixels[i])-qBlue(pixels[index]),2) +
                    pow(qGreen(pixels[i])-qGreen(pixels[index]),2));
    }

    // Odległość kątowa
    double angleDistance = 0;
    for ( int i = 0; i != pixels.size(); ++i ) {
        if ( i == index )
            continue;
        // Miara kątowa
        double licznik = qRed(pixels[i])*qRed(pixels[index]) +
                                           qGreen(pixels[i])*qGreen(pixels[index]) +
                                           qBlue(pixels[i])*qBlue(pixels[index]);
        double mianownik = countLength(pixels[i]) * countLength(pixels[index]);
        angleDistance += 1/cos(licznik/mianownik);
    }

    return (pow(distance,1-p) + pow(angleDistance,p));
}

double Controller::countLength(QRgb pixel) {

    return sqrt( qBlue(pixel)*qBlue(pixel) +
                 qRed(pixel)*qRed(pixel) +
                 qGreen(pixel)*qGreen(pixel) );

}
