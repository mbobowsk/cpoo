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
    // Obicza gługość wektora trzech  wymiarów (RGB)
    static double countLength(QRgb pixel);
    // Oblicza wartość zadanego pixela przy określonym rozmiarze okna
    QRgb adaptivePixel(QImage *original, int x, int y, int windowSize, int maxWindowSize);
    // Komparator do sortowania listy pikseli
    static bool adaptiveComparator( QRgb first, QRgb second);
    // Wypełnia granice nowego obrazka pikselami ze starego obrazka
    void fillBorders(QImage *oldImg, QImage *newImg, int border);
};

#endif // CONTROLLER_H
