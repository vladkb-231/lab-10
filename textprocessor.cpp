#include "textprocessor.h"
#include <QRegularExpression>

QString TextProcessor::normalize(const QString& text) {
    QString normalized = text.toLower();
    normalized.replace(QRegularExpression("[^a-zа-я0-9\\s]"), "");
    return normalized;
}

QSet<QString> TextProcessor::createShingles(const QString& text, int shingleSize) {
    QStringList words = text.split(" ", Qt::SkipEmptyParts);
    QSet<QString> shingles;

    for (int i = 0; i <= words.size() - shingleSize; ++i) {
        QString shingle;
        for (int j = 0; j < shingleSize; ++j) {
            shingle += words[i + j] + " ";
        }
        shingles.insert(shingle.trimmed());
    }
    return shingles;
}
