#include <iostream>

template <typename T> int binarySearch(T array[], int n, T x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (x == array[middle]) {
            return middle;
        }
        if (x > array[middle]) {
            left = middle + 1;
            continue;
        }
        right = middle - 1;
    }

    return -1;
}

int main(void) {

    float x, *A;
    int n, *B;

    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter x: ";
    std::cin >> x;

    A = new float[n];

    for (int i = 0; i < n; ++i) {
        A[i] = i * 1.1;
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    int indexOfNumber = binarySearch<float>(A, n, x);

    if (-1 != indexOfNumber) {
        std::cout << indexOfNumber << std::endl;
    } else {
        std::cout << "Number not found inside array" << std::endl;
    }

    delete [] A;

    B = new int[n];

    for (int i = 0; i < n; ++i) {
        B[i] = i + 3;
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    indexOfNumber = binarySearch<int>(B, n, x);

    if (-1 != indexOfNumber) {
        std::cout << indexOfNumber << std::endl;
    } else {
        std::cout << "Number not found inside array" << std::endl;
    }

    delete [] B;

    return EXIT_SUCCESS;
}