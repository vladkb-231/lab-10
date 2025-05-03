#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textprocessor.h"
#include "comparer.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Plagiarism Checker");
    ui->progressBar->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseInput_clicked()
{
    inputPath = QFileDialog::getOpenFileName(this, "Выберите файл для проверки", QDir::homePath(), "Text files (*.txt)");
    ui->inputPathEdit->setText(inputPath);
}

void MainWindow::on_browseSamples_clicked()
{
    samplesDir = QFileDialog::getExistingDirectory(this, "Выберите папку с образцами", QDir::homePath());
    ui->samplesDirEdit->setText(samplesDir);
}

void MainWindow::on_checkButton_clicked()
{
    if(inputPath.isEmpty() || samplesDir.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Укажите все необходимые пути!");
        return;
    }

    ui->progressBar->setVisible(true);
    ui->resultsText->clear();

    QFile inputFile(inputPath);
    if(!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не могу открыть входной файл!");
        return;
    }

    QString inputText = QTextStream(&inputFile).readAll();
    inputFile.close();

    QString normalizedInput = TextProcessor::normalize(inputText);
    QSet<QString> inputShingles = TextProcessor::createShingles(normalizedInput, 3);

    // Загрузка образцов
    QDir directory(samplesDir);
    QStringList files = directory.entryList(QStringList() << "*.txt", QDir::Files);

    if(files.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "В папке нет .txt файлов!");
        return;
    }

    ui->progressBar->setMaximum(files.size());

    for(int i = 0; i < files.size(); ++i) {
        QFile file(directory.filePath(files[i]));
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QString docText = QTextStream(&file).readAll();
            file.close();

            QString normalizedDoc = TextProcessor::normalize(docText);
            QSet<QString> docShingles = TextProcessor::createShingles(normalizedDoc, 3);

            double similarity = Comparer::compare(inputShingles, docShingles);
            ui->resultsText->appendPlainText(
                QString("%1: %2%\n%3\n")
                    .arg(files[i])
                    .arg(similarity, 0, 'f', 2)
                    .arg(docText.left(100) + "...")
                );
        }
        ui->progressBar->setValue(i+1);
    }

    ui->progressBar->setVisible(false);
    QMessageBox::information(this, "Готово", "Проверка завершена!");
}
