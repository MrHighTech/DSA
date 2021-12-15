#include <iostream>

int *squareAndRandomize(int *array, int sizeOfArray) {

    bool usedIndexes[sizeOfArray] = {0};

    int *newArray = new int[sizeOfArray];

    for (int i = 0; i < sizeOfArray; ++i) {
        int randomIndex;
        do {
            randomIndex = rand() % sizeOfArray;
            if (!usedIndexes[randomIndex]) {
                usedIndexes[randomIndex] = true;
                break;
            }
        } while(usedIndexes[randomIndex]);
        usedIndexes[randomIndex] = true;
        newArray[i] = array[randomIndex] * array[randomIndex];
    }

    return newArray;
}

int main(void) {

    srand(time(NULL));

    int n, *array, *newArray;

    std::cout << "Enter n: ";
    std::cin >> n;

    array = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter at index " << i << ": ";
        std::cin >> array[i];
    }

    newArray = squareAndRandomize(array, n);

    for (int i = 0; i < n; ++i) {
        std::cout << newArray[i] << " ";
    }

    std::cout << std::endl;

    delete [] newArray;
    delete [] array;

    return EXIT_SUCCESS;
}