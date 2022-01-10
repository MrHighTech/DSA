#include <iostream>
#include <string.h>

void Swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -=b;
}

void Selection2Sort(int arr[], int n, char direction) {
    if (direction == '0') {
        for (int i = 0; i < n; ++i) {
            int min = i;
            int max = i;
            for (int j = i + 1; j < n - i; ++j) {
                if (arr[min] < arr[j]) {
                    min = j;
                }
                if (arr[max] > arr[j]) {
                    max = j;
                }
            }
            if (min != i) {
                Swap(arr[i], arr[min]);
            }
            if (max == i) {
                Swap(arr[min], arr[n - i - 1]);
            } else {
                if (max != n - i - 1)
                    Swap(arr[max], arr[n - i - 1]);
            }

        }

        return;
    }

    if (direction == '1') {
        for (int i = 0; i < n; ++i) {
            int min = i;
            int max = i;
            for (int j = i + 1; j < n - i; ++j) {
                if (arr[min] > arr[j]) {
                    min = j;
                }
                if (arr[max] < arr[j]) {
                    max = j;
                }
            }
            if (min != i) {
                Swap(arr[i], arr[min]);
            }
            if (max == i) {
                Swap(arr[min], arr[n - i - 1]);
            } else {
                if (max != n - i - 1)
                    Swap(arr[max], arr[n - i - 1]);
            }

        }

        return;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "[" << i << "] " << arr[i] << std::endl;
    }
}



int main(void) {

    int n;
    char direction;

    std::cout << "Enter n: ";
    std::cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {

        std::cout << "Enter number: ";
        std::cin >> arr[i];
    }

    std::cout << "Enter sort direction [0 - ascending | 1 - descending]: ";
    std::cin >> direction;

    print(arr, n);
    std::cout << std::endl;

    Selection2Sort(arr, n, direction);

    print(arr, n);

    return EXIT_SUCCESS;
}