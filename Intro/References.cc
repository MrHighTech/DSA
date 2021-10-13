#include <iostream>

using namespace std;

class Fraction {
    public:
        uint32_t n;
        uint32_t d;
        Fraction *fract;
        Fraction() : n(0), d(0) {}
        Fraction(uint32_t n, uint32_t d) : n(n), d(d) {}
        ~Fraction() {
            delete fract;
        }
        Fraction(const Fraction &f) {
            this->n = f.n;
            this->d = f.d;
            this->fract = f.fract;
        }
};

void f() {
    Fraction *f = new Fraction(); // Has to be removed from memory manually
    Fraction f1; // Calling auto destructor
    delete f;
}

void copyConstructor(Fraction x) {
    // New fraction object
}

int main(void) {
    f();
    Fraction x;
    copyConstructor(x);

    return EXIT_SUCCESS;
}