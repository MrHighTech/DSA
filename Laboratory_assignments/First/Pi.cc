#include <iostream>

double pi(int n) {
    if (n == 1) {
        return 4.0;
    }
    if (0 == n % 2) {
        return pi(n - 1) - 4.0 / (n * 2 - 1);
    }

    return pi(n - 1) + 4.0 / (n * 2 - 1);
}

int main(void) {

    double *array;
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    array = new double[n];

    for (int i = 0; i < n; ++i) {
        array[i] = pi(i + 1);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    delete [] array;

    return EXIT_SUCCESS;
}