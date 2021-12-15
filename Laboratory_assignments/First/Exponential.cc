#include <iostream>
#include <cmath>

double exp(double x, int n, int *fakt, double *xpot) {
    if (0 == n) {
        return 1;
    }

    double result = exp(x, n - 1, fakt, xpot) + *xpot / (double) *fakt;

    *fakt *= n + 1;
    *xpot *= x;

    return result;
}

int main(void) {

    double *A, x, xpot;
    int n, fakt;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter x: ";
    std::cin >> x;

    A = new double[n];

    for (int i = 0; i < n; ++i) {
        fakt = 1;
        xpot = x;
        A[i] = exp(x, i, &fakt, &xpot);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }

    std::cout << std::endl;

    delete [] A;

    return EXIT_SUCCESS;
}