#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QString>
#include <QSet>

class TextProcessor {
public:
    static QString normalize(const QString& text);
    static QSet<QString> createShingles(const QString& text, int shingleSize);
};

#endif // TEXTPROCESSOR_H
