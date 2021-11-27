#include <iostream>

template <typename T> class Point {
    public:
        T x;
        T y;
        Point(): x(x), y(y) {}
};

template <class C1, class C2> class Pair {
    public:
        C1 el1;
        C2 el2;
        Pair() {}
        Pair(C1 c1, C2 c2) : el1(c1), el2(c2) {}

};

int main(void) {

    Point<int> point1;
    Point<double> point2;

    Pair<Point<int>, Point<double>> pair1;
    pair1.el1.x;
    return EXIT_SUCCESS;
}