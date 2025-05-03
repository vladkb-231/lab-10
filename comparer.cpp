#include "comparer.h"

double Comparer::compare(const QSet<QString>& setA, const QSet<QString>& setB) {
    int intersection = 0;
    for (const QString& shingle : setA) {
        if (setB.contains(shingle)) {
            intersection++;
        }
    }
    return (2.0 * intersection) / (setA.size() + setB.size()) * 100; // Коэффициент Жаккара
}
