#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseInput_clicked();
    void on_browseSamples_clicked();
    void on_checkButton_clicked();

private:
    Ui::MainWindow *ui;
    QString inputPath;
    QString samplesDir;
};

#endif // MAINWINDOW_H
