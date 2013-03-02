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
};

#endif // CONTROLLER_H
