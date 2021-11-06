#include <iostream>

class Shape {
    public:
        uint32_t x;
        uint32_t y;
        Shape() {}
        Shape(uint32_t x, uint32_t y) : x(x), y(y) {}
};

class Rectangle : public Shape {
    public:
        uint32_t a;
        uint32_t b;
        Rectangle() {}
        Rectangle(uint32_t x, uint32_t y, uint32_t a, uint32_t b) :
            Shape(x, y), a(a), b(b) {}
};

class Point {
    private:
        int x;
        int y;
        friend void setX(Point &p, uint32_t x);
        friend void setY(Point &p, uint32_t y);
        friend class X;
};

void setX(Point &p, uint32_t x) {
    p.x = x;
}

void setY(Point &p, uint32_t y) {
    p.y = y;
}

class X {
    private:
        void f() {
            Point p;
            p.x = 0;
        }
    public:
        static uint32_t numOfInstances;
        void resetNumOfInstances() {
            numOfInstances = 0;
        }
        X(){
            X::numOfInstances++;
        }
};

uint32_t X::numOfInstances = 0;

uint32_t main(void) {

    Shape s;
    Rectangle r;


    return EXIT_SUCCESS;
}