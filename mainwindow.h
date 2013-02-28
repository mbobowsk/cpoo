#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Controller* controller;
    QImage* sourceImage;
    QImage* resultImage;

public slots:
    void openImage();
    void saveImage();
    void runAlgorithm();
    void about();
};

#endif // MAINWINDOW_H
