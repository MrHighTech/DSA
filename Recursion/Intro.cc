#include <iostream>

void f(int i) {
    if (i < 9) {
        f(i + 1);
    }
    std::cout << i << " ";
}

int pow(int x, int y) {
    if (y <= 0) return 1;
    return x * pow(x, y - 1);
}

int fact(int x) {
    if (x <= 1) return 1;
    return x * fact(x - 1);
}

int fibonacci(int n) {
    if (n <= 1) return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(void) {

    f(0);
    std::cout << std::endl;

    int a = pow(5, 3);
    std::cout << a << std::endl;

    a = fact(5);
    std::cout << a << std::endl;

    a = fibonacci(5);
    std::cout << a << std::endl;

    return EXIT_SUCCESS;
}