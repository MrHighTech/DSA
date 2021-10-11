#include <iostream>

using namespace std;

class Fraction {
    private:
        uint32_t numerator;
        uint32_t denominator;
    public:
        Fraction() {}
        Fraction (uint32_t numerator, uint32_t denominator) : 
            numerator(numerator), denominator(denominator) {}
        uint32_t getNumerator() {
            return numerator;
        }
        uint32_t getDenominator() {
            return denominator;
        }
        Fraction operator+(const Fraction &second) {
            Fraction result;
            result.numerator = (this->numerator * second.denominator) +
                (second.numerator * this->denominator);
            result.denominator = this->denominator * second.denominator;

            return result;
        }
        friend ostream &operator<<(ostream &o, Fraction &second) {
            o << "Rezultat = (" << second.getNumerator() << "/" <<
                second.getDenominator() << ")" << endl;
            return o;
        }
};

int main(void) {

    Fraction a(2, 3);
    Fraction b(4, 5);

    Fraction c;
    c = a + b;
    cout << "Rezultat = (" << c.getNumerator() << "/" << c.getDenominator() <<
         ")" << endl;

    cout << c; // Using operator overloading to print


    return EXIT_SUCCESS;
}