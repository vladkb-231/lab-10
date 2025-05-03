/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *inputLayout;
    QLineEdit *inputPathEdit;
    QPushButton *browseInput;
    QHBoxLayout *samplesLayout;
    QLineEdit *samplesDirEdit;
    QPushButton *browseSamples;
    QPushButton *checkButton;
    QProgressBar *progressBar;
    QPlainTextEdit *resultsText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName("inputLayout");
        inputPathEdit = new QLineEdit(centralwidget);
        inputPathEdit->setObjectName("inputPathEdit");

        inputLayout->addWidget(inputPathEdit);

        browseInput = new QPushButton(centralwidget);
        browseInput->setObjectName("browseInput");

        inputLayout->addWidget(browseInput);


        verticalLayout->addLayout(inputLayout);

        samplesLayout = new QHBoxLayout();
        samplesLayout->setObjectName("samplesLayout");
        samplesDirEdit = new QLineEdit(centralwidget);
        samplesDirEdit->setObjectName("samplesDirEdit");

        samplesLayout->addWidget(samplesDirEdit);

        browseSamples = new QPushButton(centralwidget);
        browseSamples->setObjectName("browseSamples");

        samplesLayout->addWidget(browseSamples);


        verticalLayout->addLayout(samplesLayout);

        checkButton = new QPushButton(centralwidget);
        checkButton->setObjectName("checkButton");

        verticalLayout->addWidget(checkButton);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");

        verticalLayout->addWidget(progressBar);

        resultsText = new QPlainTextEdit(centralwidget);
        resultsText->setObjectName("resultsText");

        verticalLayout->addWidget(resultsText);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Plagiarism Checker", nullptr));
        browseInput->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273...", nullptr));
        browseSamples->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\320\260\320\277\320\272\321\203...", nullptr));
        checkButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\275\320\260 \320\277\320\273\320\260\320\263\320\270\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
