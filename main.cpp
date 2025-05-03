#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include "textprocessor.h"
#include "comparer.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Настройка аргументов командной строки
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument("input", "Путь к проверяемому файлу");
    parser.addPositionalArgument("samples", "Путь к папке с эталонными документами");
    parser.process(app);

    if (parser.positionalArguments().size() < 2) {
        qCritical() << "Укажите оба пути: проверяемый файл и папка с эталонными документами!";
        return 1;
    }

    QString inputPath = parser.positionalArguments()[0];   // Например, "C:/Users/drego/Desktop/input.txt"
    QString samplesDir = parser.positionalArguments()[1];  // Например, "C:/Users/drego/Desktop/samples"

    // Загрузка проверяемого файла
    QFile inputFile(inputPath);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Ошибка открытия файла:" << inputPath;
        return 1;
    }
    QTextStream inInput(&inputFile);
    QString inputText = inInput.readAll();
    inputFile.close();

    // Загрузка эталонных документов из папки
    QDir directory(samplesDir);
    QStringList files = directory.entryList(QStringList() << "*.txt", QDir::Files);
    if (files.isEmpty()) {
        qCritical() << "В папке" << samplesDir << "нет .txt файлов!";
        return 1;
    }

    QVector<QString> documents;
    foreach (QString filename, files) {
        QFile file(directory.filePath(filename));
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            documents.append(in.readAll());
            file.close();
        } else {
            qWarning() << "Не удалось открыть файл:" << filename;
        }
    }

    // Обработка текста
    QString normalizedInput = TextProcessor::normalize(inputText);
    QSet<QString> inputShingles = TextProcessor::createShingles(normalizedInput, 3);

    // Сравнение с каждым эталонным документом
    for (const QString& doc : documents) {
        QString normalizedDoc = TextProcessor::normalize(doc);
        QSet<QString> docShingles = TextProcessor::createShingles(normalizedDoc, 3);
        double similarity = Comparer::compare(inputShingles, docShingles);
        qInfo() << "Схожесть с" << files[documents.indexOf(doc)] << ":" << similarity << "%";
    }

    return 0;
}
