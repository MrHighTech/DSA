#include <iostream>

template <typename T> class ISearch{
    public:
        virtual bool Search(T A[], int n, T item) = 0;
};

template <typename T> class BinarySearch : public ISearch<T> {
    public:
        bool Search(T A[], int n, T item) {
            bool result = false;
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                std::cout << "left " << left << std::endl;
                std::cout << "right " << right << std::endl;
                int middle = (left + right) / 2;

                std::cout << middle << std::endl;
                if (A[middle] == item) {
                    result = true;
                    break;
                }

                if (A[middle] < item) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }

            return result;
        }
};

int main(void) {

    int *A = new int[8] {1, 2, 3, 4, 5, 6, 7, 8};
    BinarySearch<int> bs;
    bool result = bs.Search(A, 8, 0);
    std::cout << "Result: " << result << std::endl;
    delete [] A;
    return EXIT_SUCCESS;
}