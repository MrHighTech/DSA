#include <iostream>

static void Swap(int &a, int &b) {
    a += b;
    b = a - b;
    a -= b;
}

template <typename T>
static void PrintArray(T A[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
static void SelectionSort(T A[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        size_t index = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (A[j] < A[index]) {
                index = j;
            }
        }

        Swap(A[i], A[index]);
    }
}

template <typename T>
static void BubbleSort(T A[], size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (A[j + 1] < A[j]) {
                Swap(A[j], A[j + 1]);
            }
        }
    }
}

template <typename T>
static void BubbleSortEnhanced(T A[], size_t n) {
    bool swapped = true;
    for (size_t i = 0; swapped; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (A[j + 1] < A[j]) {
                Swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
    }
}

template <typename T>
static void InsertionSort(T A[], size_t n) {
    T tmp;
    for (size_t i = 1; i < n; ++i) {
        size_t j;
        tmp = A[i];
        for (j = i; j >= 1 && A[j - 1] > tmp; --j) {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

template <typename T>
static void ShellSort(T A[], size_t n) {
    T tmp;
    int numSteps = 3;
    int steps[numSteps] = {4, 2, 1};
    for (int i = 0; i < numSteps; ++i) {
        for (size_t j = steps[i]; j < n; ++j) {
            size_t k;
            tmp = A[j];
            for (k = j; k >= steps[i] && A[k - 1] > tmp; k -= steps[i]) {
                A[k] = A[k - steps[i]];
            }
            A[k] = tmp;
        }
    }
}

template <typename T>
static void MergeArrays(T A[], T tmpArray[], size_t left, size_t middle, size_t right) {
    size_t tmpPosition = left;
    size_t numOfElements = right - left + 1;
    while(left <= right - 1 && middle <= right) {
        if (A[left] <= A[middle]) {
            tmpArray[tmpPosition++] = A[left++];
            continue;
        }

        tmpArray[tmpPosition++] = A[middle++];
    }
    while(left <= right - 1) {
        tmpArray[tmpPosition++] = A[left++];
    }
    while(left <= right - 1) {
        tmpArray[tmpPosition++] = A[middle++];
    }

    for (int i = 0; i < numOfElements; ++i, --right) {
        A[right] = tmpArray[right];
    }
}

template <typename T>
static void MergeSortRecursive(T A[], T tmpArray[], size_t left, size_t right) {
    size_t middle;
    if (left < right) {
        middle = (left + right) / 2;
        MergeSortRecursive(A, tmpArray, left, middle);
        MergeSortRecursive(A, tmpArray, middle + 1, right);
        MergeArrays(A, tmpArray, left, middle + 1, right);
    }
}

template <typename T>
static void QuickSort(T A[], size_t n) {
    
};

int main(void) {

    int array[10] = {8, 15, 3, 4, 5, 1, 7, 6, 2, 0};
    //int tmpArray[10];
    PrintArray(array, 10);
    //MergeSortRecursive(array, tmpArray, 0, 10);
    QuickSort(array, 10);
    PrintArray(array, 10);
    return EXIT_SUCCESS;
}