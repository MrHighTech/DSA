#include <iostream>

using namespace std;

namespace n1 {
    double PI = 3.14;
}

namespace n2 {
    double PI = 3.141;
}

using namespace n1;

int square(int x) {
    cout << "Int function" << endl;
    return x*x;
}

double square(double x) {
    cout << "Double function" << endl;
    return x*x;
}

void swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "Variables are swapped" << endl;
}

class Point {
    int x;
    int y;
    public:
        Point() : x(0), y(0) {
            cout << "Initialized object to all 0s" << endl;
        }
        Point(int x, int y) : x(x), y(y) {}
        ~Point(){
            cout << "In destructor" << endl;
        }
};

void f() {
    cout << "f entrance" << endl;
    Point p1;
    cout << "f exit" << endl;
}

int main(void) {
    cout << "Hello, World!" << endl;
    cout << PI << endl;
    cout << n2::PI << endl;

    /* int x;
    cin >> x;
    cout << x << endl; */

    int s1 = square(2);
    int s2 = square(3.0);

    cout << "First: " << s1 << endl;
    cout << "Second: " << s2 << endl;

    swap(s1, s2);

    cout << "First: " << s1 << endl;
    cout << "Second: " << s2 << endl;

    Point p1 {3, 4};
    Point p2;

    cout << "Before f" << endl;
    f();
    cout << "After f" << endl;


    return EXIT_SUCCESS;
}