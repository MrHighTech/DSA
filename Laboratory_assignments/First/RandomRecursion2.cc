#include <iostream>
#include <cmath>

// Recursion looks like
// ((-1)^k * z^(2k + 1)) / ((2k+1)!)
double f(double z, int k) {
    if (0 == k) {
        return z;
    }

    return (-1 * pow(z, 2) * f(z, k - 1)) / (((2 * k) + 1) * (2 * k));
}

int main(void) {

    double z = 0.5; // Defined by the task

    for (int i = 0; i < 10; ++i) {
        std::cout << f(z, i) << std::endl;
    }

    return EXIT_SUCCESS;
}