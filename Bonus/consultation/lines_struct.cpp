#include <iostream>
#include <valarray>

using namespace std;

struct line {
    double startX;
    double startY;
    double endX;
    double endY;
};

double lengthOfLine(line l) {
    double squaredDistance = (l.startX - l.endX) * (l.startX - l.endX) + (l.startY - l.endY) * (l.startY - l.endY);


    return sqrt(squaredDistance);
}

bool isParallel(const line &l1) {
    return l1.endX == l1.startX || l1.endY == l1.startY;
}

bool areOnOneLine(const line &l1, const line &l2) {
    return (l1.startX == l2.startX && l1.endX == l2.endX) || (l1.startY == l2.startY && l1.endY == l2.endY);
}

double min(double a, double b) {
    return a < b ? a : b;
}

double max(double a, double b) {
    return a > b ? a : b;
}

double getCommonDistance(const line &l1, const line &l2) {
    if (!isParallel(l1) || !isParallel(l2)) {
        return -1;
    }

    if (!areOnOneLine(l1, l2)) {
        return 0;
    }

    if (l1.startX == l2.startX) {
        return min(l1.endY, l2.endY) - max(l1.startY, l2.startY);
    }

    return min(l1.endX, l2.endX) - max(l1.startX, l2.startX);
}

int main() {
    line l1{10, 10, 10, 35};

    line l2;
    l2.startX = 10;
    l2.startY = 10;
    l2.endX = 0;
    l2.endY = 10;

    cout << getCommonDistance(l1, l2) << endl;
}
