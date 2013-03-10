#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QImage>
#include <vector>

/** Klasa kontrolera */
class Controller
{
public:
    Controller();
    // Zwraca NULL w przypadku niepowodzenia
    QImage* median(QImage *oldImg);
    QImage* adaptMedian(QImage *oldImg);

private:
    static bool sortRgb(QRgb a, QRgb b);
    // Oblicza sumę odległości piksela o podanym indeksie
    int countDst(std::vector<unsigned>& pixels, int index);
    // Wypełnia granice nowego obrazka pikselami ze starego obrazka
    void fillBorders(QImage *oldImg, QImage *newImg, int border);
};

#endif // CONTROLLER_H
