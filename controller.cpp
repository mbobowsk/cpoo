#include "controller.h"

//TODO remove
#include <QDebug>

Controller::Controller()
{
}

// Filtracja medianowa zwykła
QImage* Controller::median(QImage *oldImg) {
    qDebug()<<"mediana zwykła";
    return NULL;
}

// Adaptacyjna filtracja medianowa
QImage* Controller::adaptMedian(QImage *oldImg) {
    qDebug()<<"mediana adaptacyjna";
    return NULL;
}


