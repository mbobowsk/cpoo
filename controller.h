#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QImage>

/** Klasa kontrolera */
class Controller
{
public:
    Controller();
    // Zwraca NULL w przypadku niepowodzenia
    QImage* median(QImage *oldImg);
    QImage* adaptMedian(QImage *oldImg);
};

#endif // CONTROLLER_H
