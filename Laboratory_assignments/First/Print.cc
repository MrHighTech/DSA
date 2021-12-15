#include <iostream>

void print(float array[], int n) {
    if (n > 0) {
        print(array, n - 1);
    }

    if (array[n] < 0) {
        std::cout << array[n] << std::endl;
    }
}


int main(void) {

    float *A;
    int n;

    std::cout << "Enter length of array: " << std::endl;
    std::cin >> n;

    A = new float[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter at index " << i << " " << std::endl;
        std::cin >> A[i];
        std::cout << A[i] << std::endl;
    }

    print(A, n);

    delete [] A;

    return EXIT_SUCCESS;
}