#ifndef COMPARER_H
#define COMPARER_H

#include <QSet>

class Comparer {
public:
    static double compare(const QSet<QString>& setA, const QSet<QString>& setB);
};

#endif // COMPARER_H
