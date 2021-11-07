#include <iostream>
#include <cmath>

template <typename T> class ISearch{
    public:
        virtual bool Search(T A[], int n, T item) = 0;
};

template <typename T> class BlockSearch : public ISearch<T> {
    public:
        bool Search(T A[], int n, T item) {
            bool found = false;
            int blockStart = 0;
            int blockSize = std::sqrt(n);
            int blockEnd = blockSize;

            while (blockEnd < n && A[blockEnd] < item) {
                blockStart += blockSize;
                blockEnd += blockSize;
            }

            if (blockEnd >= n) {
                blockEnd = n - 1;
            }

            for (int i = blockStart; i <= blockEnd; ++i) {
                if (A[i] == item) {
                    found = true;
                    break;
                }
            }

            return found;
        }
};

int main(void) {

    int *A = new int[16] {1, 2, 3, 4, 5, 6, 7, 8, 9,
                          10, 11, 12, 13, 14, 15, 16};
    BlockSearch<int> bs;
    for (int i = -100; i < 100; ++i) {
        bool result = bs.Search(A, 16, i + 1);
        std::cout << "[" << i + 1 << "] Result: " << result << std::endl;
    }
    delete [] A;

    return EXIT_SUCCESS;
}