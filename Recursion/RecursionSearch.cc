#include <iostream>

template <typename T> class ISearch{
    public:
        virtual bool Search(T A[], int n, T item) = 0;
};

template <typename T> class LinearSearchRecursion : public ISearch<T>{
    public:
        bool Search(T A[], int n, T item) {
            if (n <= 0) return false;

            if (A[n - 1] == item) {
                return true;
            }

            return Search(A, n - 1, item);

        }
        LinearSearchRecursion() {}

};

template <typename T> class BinarySearchRecursion : public ISearch<T> {
    public:
        bool Search(T A[], int n, T item) {
            return Search_internal(A, 0, n - 1, item);
        }
        BinarySearchRecursion() {}
    private:
        bool Search_internal(T A[], int left, int right, T item) {

            if (left > right) {
                return false;
            }

            int middle = (left + right) / 2;
            if (A[middle] == item) {
                return true;
            }

            if (A[middle] > item) {
                return Search_internal(A, left, middle - 1, item); // Left side of recursion
            }

            return Search_internal(A, middle + 1, right, item); // Right side of recursion
        }
};


int main(void) {

    int *A = new int[3] {1, 2, 3};
    LinearSearchRecursion<int> ls;

    bool result = ls.Search(A, 3, 5);
    std::cout << "Result: " << result << std::endl;

    delete [] A;

    A = new int[8] {1, 2, 3, 4, 5, 6, 7, 8};
    BinarySearchRecursion<int> bs;

    bool result2 = bs.Search(A, 8, 1);
    std::cout << "Result: " << result2 << std::endl;

    delete [] A;

    return EXIT_SUCCESS;
}