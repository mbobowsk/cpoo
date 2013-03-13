#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    setWindowTitle(tr("Filtracja medianowa"));
    ui->setupUi(this);
    controller = new Controller();

    connect(ui->actionOpenImage, SIGNAL(triggered()), this, SLOT(openImage()));
    connect(ui->actionSaveResult, SIGNAL(triggered()), this, SLOT(saveImage()));
    connect(ui->actionRunAlgorithm, SIGNAL(triggered()), this, SLOT(runAlgorithm()));
    connect(ui->actionShowHelp, SIGNAL(triggered()), this, SLOT(about()));

    connect(ui->originalScrollArea->horizontalScrollBar(), SIGNAL(valueChanged(int)), ui->resultScrollArea->horizontalScrollBar(), SLOT(setValue(int)));
    connect(ui->originalScrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->resultScrollArea->verticalScrollBar(), SLOT(setValue(int)));
    connect(ui->resultScrollArea->horizontalScrollBar(), SIGNAL(valueChanged(int)), ui->originalScrollArea->horizontalScrollBar(), SLOT(setValue(int)));
    connect(ui->resultScrollArea->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->originalScrollArea->verticalScrollBar(), SLOT(setValue(int)));

    ui->saveButton->setEnabled(false);
    ui->runAlgorithmButton->setEnabled(false);
    ui->actionSaveResult->setEnabled(false);
    ui->actionRunAlgorithm->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::openImage(){
    QString path = QFileDialog::getOpenFileName(this, tr("Otwórz obrazek"), ".", tr("Images (*.bmp *.dib *.jpeg *.jpg *.jpe *.jp2 *.png *.pbm *.pgm *.ppm *.sr *.ras *.tiff *.tif)"));

    if (!path.isEmpty()){
        sourceImage = new QImage(path);
        ui->originalImageLabel->resize(sourceImage->width(), sourceImage->height());
        ui->originalImageLabel->setPixmap(QPixmap::fromImage(*sourceImage));

        ui->originalImageLabel->show();
        ui->resultImageLabel->setPixmap(QPixmap());
        ui->runAlgorithmButton->setEnabled(true);
        ui->actionRunAlgorithm->setEnabled(true);
    }
}

void MainWindow::saveImage(){
    if (resultImage != NULL){
        QString filePath = QFileDialog::getSaveFileName(this,"Zapisz obrazek", ".");
        if ( !filePath.isNull() ) {
            if (!resultImage->save(filePath))
            {
                QMessageBox::critical(this, tr("Problem przy zapisie"), tr("Wystąpił problem podczas zapisywania.\nObrazek nie został zapisany."));
            }
        }
    }
}

void MainWindow::runAlgorithm(){
    if (ui->algorithmsCombo->currentIndex() != -1){
        switch (ui->algorithmsCombo->currentIndex()) {
        case 0:
            resultImage = controller->median(sourceImage);
            break;
        case 1:
            resultImage = controller->adaptMedian(sourceImage);
            break;
        }
        if (resultImage == NULL){
            QMessageBox::critical(this, tr("Problem przy filtracji"), tr("Wystąpił problem podczas filtrowania."));
            return;
        }
        ui->resultImageLabel->resize(resultImage->width(), resultImage->height());
        ui->resultImageLabel->setPixmap(QPixmap::fromImage(*resultImage));

        ui->actionSaveResult->setEnabled(true);
        ui->saveButton->setEnabled(true);
    }
}

void MainWindow::about(){
    QMessageBox::about(this, tr("O Programie"),
                       tr("<p>Ogólna i adaptacyjna filtracja medianowa</p>\nProjekt w ramach CPOO 2013<p>\n Michał Bobowski i Andrzej Dudziec"));
}
