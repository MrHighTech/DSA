#include <iostream>
#include <cmath>

int addSquares(int *array, int n) {
    if (0 == n) {
        return 0;
    }

    if (sqrt(*array) - floor(sqrt(*array)) == 0.0) {

        return addSquares(array + 1, n - 1) + sqrt(*array);
    }

    return addSquares(array + 1, n - 1);
}

void randomizeArray(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        *(array + i) = rand() % 100 + 1;
        std::cout << *(array + i) << " ";
    }
}


// Create array of n random elements and add all numbers that are real squaress
int main(void) {
    srand(time(NULL));

    int *array, n;
    std::cout << "Insert n: ";
    std::cin >> n;

    array = new int[n];

    randomizeArray(array, n);

    std::cout << std::endl;

    std::cout << addSquares(array, n) << std::endl;

    delete [] array;

    return EXIT_SUCCESS;
}