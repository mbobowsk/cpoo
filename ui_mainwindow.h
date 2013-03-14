/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Mar 14 21:35:59 2013
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenImage;
    QAction *actionSaveResult;
    QAction *actionShowHelp;
    QAction *actionRunAlgorithm;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *leftArea;
    QVBoxLayout *verticalLayout;
    QScrollArea *originalScrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *originalImageLabel;
    QWidget *selectedAlgorithmPanel;
    QFormLayout *formLayout;
    QLabel *algorithmLabel;
    QComboBox *algorithmsCombo;
    QWidget *rightArea;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *resultScrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *resultImageLabel;
    QWidget *buttonsPanel;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *runAlgorithmButton;
    QPushButton *openImage;
    QPushButton *saveButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QComboBox *windowSizeCombo;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *parameterPSpinner;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpenImage = new QAction(MainWindow);
        actionOpenImage->setObjectName(QString::fromUtf8("actionOpenImage"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/open_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenImage->setIcon(icon1);
        actionSaveResult = new QAction(MainWindow);
        actionSaveResult->setObjectName(QString::fromUtf8("actionSaveResult"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveResult->setIcon(icon2);
        actionShowHelp = new QAction(MainWindow);
        actionShowHelp->setObjectName(QString::fromUtf8("actionShowHelp"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowHelp->setIcon(icon3);
        actionRunAlgorithm = new QAction(MainWindow);
        actionRunAlgorithm->setObjectName(QString::fromUtf8("actionRunAlgorithm"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRunAlgorithm->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        leftArea = new QWidget(centralWidget);
        leftArea->setObjectName(QString::fromUtf8("leftArea"));
        verticalLayout = new QVBoxLayout(leftArea);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        originalScrollArea = new QScrollArea(leftArea);
        originalScrollArea->setObjectName(QString::fromUtf8("originalScrollArea"));
        originalScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 250, 224));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        originalImageLabel = new QLabel(scrollAreaWidgetContents);
        originalImageLabel->setObjectName(QString::fromUtf8("originalImageLabel"));

        gridLayout->addWidget(originalImageLabel, 0, 0, 1, 1);

        originalScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(originalScrollArea);

        selectedAlgorithmPanel = new QWidget(leftArea);
        selectedAlgorithmPanel->setObjectName(QString::fromUtf8("selectedAlgorithmPanel"));
        formLayout = new QFormLayout(selectedAlgorithmPanel);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        algorithmLabel = new QLabel(selectedAlgorithmPanel);
        algorithmLabel->setObjectName(QString::fromUtf8("algorithmLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, algorithmLabel);

        algorithmsCombo = new QComboBox(selectedAlgorithmPanel);
        algorithmsCombo->setObjectName(QString::fromUtf8("algorithmsCombo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(algorithmsCombo->sizePolicy().hasHeightForWidth());
        algorithmsCombo->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, algorithmsCombo);


        verticalLayout->addWidget(selectedAlgorithmPanel);


        horizontalLayout_5->addWidget(leftArea);

        rightArea = new QWidget(centralWidget);
        rightArea->setObjectName(QString::fromUtf8("rightArea"));
        verticalLayout_2 = new QVBoxLayout(rightArea);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        resultScrollArea = new QScrollArea(rightArea);
        resultScrollArea->setObjectName(QString::fromUtf8("resultScrollArea"));
        resultScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 283, 224));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        resultImageLabel = new QLabel(scrollAreaWidgetContents_2);
        resultImageLabel->setObjectName(QString::fromUtf8("resultImageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(resultImageLabel->sizePolicy().hasHeightForWidth());
        resultImageLabel->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(resultImageLabel, 0, 0, 1, 1);

        resultScrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(resultScrollArea);

        buttonsPanel = new QWidget(rightArea);
        buttonsPanel->setObjectName(QString::fromUtf8("buttonsPanel"));
        horizontalLayout_3 = new QHBoxLayout(buttonsPanel);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        runAlgorithmButton = new QPushButton(buttonsPanel);
        runAlgorithmButton->setObjectName(QString::fromUtf8("runAlgorithmButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(runAlgorithmButton->sizePolicy().hasHeightForWidth());
        runAlgorithmButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(runAlgorithmButton);

        openImage = new QPushButton(buttonsPanel);
        openImage->setObjectName(QString::fromUtf8("openImage"));
        sizePolicy2.setHeightForWidth(openImage->sizePolicy().hasHeightForWidth());
        openImage->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(openImage);

        saveButton = new QPushButton(buttonsPanel);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout_2->addWidget(buttonsPanel);


        horizontalLayout_5->addWidget(rightArea);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        windowSizeCombo = new QComboBox(groupBox_2);
        windowSizeCombo->setObjectName(QString::fromUtf8("windowSizeCombo"));

        gridLayout_3->addWidget(windowSizeCombo, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        parameterPSpinner = new QDoubleSpinBox(groupBox_3);
        parameterPSpinner->setObjectName(QString::fromUtf8("parameterPSpinner"));
        parameterPSpinner->setMaximum(1);
        parameterPSpinner->setSingleStep(0.1);

        gridLayout_4->addWidget(parameterPSpinner, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_5->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 25));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(actionOpenImage);
        menuPlik->addAction(actionSaveResult);
        menuPlik->addSeparator();
        menuPlik->addAction(actionRunAlgorithm);
        menuPlik->addSeparator();
        menuPlik->addAction(actionExit);
        menuPomoc->addAction(actionShowHelp);
        mainToolBar->addAction(actionOpenImage);
        mainToolBar->addAction(actionSaveResult);

        retranslateUi(MainWindow);
        QObject::connect(saveButton, SIGNAL(clicked()), actionSaveResult, SLOT(trigger()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(runAlgorithmButton, SIGNAL(clicked()), actionRunAlgorithm, SLOT(trigger()));
        QObject::connect(openImage, SIGNAL(clicked()), actionOpenImage, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpenImage->setText(QApplication::translate("MainWindow", "Otw\303\263rz obrazek", 0, QApplication::UnicodeUTF8));
        actionOpenImage->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSaveResult->setText(QApplication::translate("MainWindow", "Zapisz rezultat", 0, QApplication::UnicodeUTF8));
        actionSaveResult->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionShowHelp->setText(QApplication::translate("MainWindow", "O Programie", 0, QApplication::UnicodeUTF8));
        actionShowHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", 0, QApplication::UnicodeUTF8));
        actionRunAlgorithm->setText(QApplication::translate("MainWindow", "Uruchom algorytm", 0, QApplication::UnicodeUTF8));
        actionRunAlgorithm->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Zako\305\204cz", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        originalImageLabel->setText(QString());
        algorithmLabel->setText(QApplication::translate("MainWindow", "Algorytm: ", 0, QApplication::UnicodeUTF8));
        algorithmsCombo->clear();
        algorithmsCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Mediana uog\303\263lniona", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mediana adaptacyjna", 0, QApplication::UnicodeUTF8)
        );
        resultImageLabel->setText(QString());
        runAlgorithmButton->setText(QApplication::translate("MainWindow", "Dzia\305\202aj", 0, QApplication::UnicodeUTF8));
        openImage->setText(QApplication::translate("MainWindow", "Otw\303\263rz", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("MainWindow", "Zapisz", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Parametry", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Rozmiar okna", 0, QApplication::UnicodeUTF8));
        windowSizeCombo->clear();
        windowSizeCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3x3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5x5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7x7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9x9", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Parametr p", 0, QApplication::UnicodeUTF8));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
