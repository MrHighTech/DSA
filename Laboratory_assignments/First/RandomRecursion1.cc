#include <iostream>
#include <cmath>

// Insert m^i at the index i
void recursion(int polje[], int n, int m) {
    if (0 == n) {
        polje[n] = 1;
        return;
    }

    recursion(polje, n - 1, m);

    polje[n] = pow(m, n);
}

int main(void) {

    int n, m, *array;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    array = new int[n];

    recursion(array, n, m);

    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}