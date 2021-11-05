#include <iostream>

template <typename T> class ISearch{
    public:
        virtual bool Search(T A[], int n, T item) = 0;
};

template <typename T> class LinearSearch : public ISearch<T>{
    public:
        bool Search(T A[], int n, T item) {
            bool result = false;
            for (int i = 0; i < n; i++) {
                if (A[i] == item) {
                    result = true;
                    break;
                }
            }

            return result;
        }
        LinearSearch() {}

};


int main(void) {
    int *A = new int[3] {1, 2, 3};
    LinearSearch<int> ls;

    bool result = ls.Search(A, 3, 5);
    std::cout << "Result " << result << std::endl;

    delete [] A;
    return EXIT_SUCCESS;
}