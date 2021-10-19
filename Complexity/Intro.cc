#include <iostream>

#define N 100

int main(void) {
    uint32_t counter = 0;
    uint32_t tmp = 0;

    ++counter; // For i = 0
    for (uint32_t i = 0; i < N; ++i) {
        ++counter; // For each <
        ++counter; // For each ++i
        ++tmp;
        ++counter; // For each ++tmp

        ++counter; // For j = 0
        for (uint32_t j = 0; j < N; ++j) {
            ++counter; // For each <
            ++counter; // For each ++j
            ++tmp;
            ++counter; // For each ++tmp
        }
        ++counter; // For last <
    }
    ++counter; // For last <

    std::cout << "Broj operacije: " << counter << std::endl;


    return EXIT_SUCCESS;
}