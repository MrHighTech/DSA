#include <iostream>

// Funciton takes in any string and returns the same string with only
// English alphabet letters
char *leaveLetters(std::string entry) {

    int numOfLetters = 0, filledLetters = 0;

    for (int i = 0; i < entry.size(); ++i) {
        if (entry[i] >= 'a' && entry[i] <= 'z' || entry[i] >= 'A' && entry[i] <= 'Z' ) {
            ++numOfLetters;
        }
    }

    char *newString = new char[numOfLetters];

    for (int i = 0; i < entry.size(); ++i) {
        if (entry[i] >= 'a' && entry[i] <= 'z' || entry[i] >= 'A' && entry[i] <= 'Z' ) {
            newString[filledLetters++] = entry[i];
        }
    }

    return newString;
}

int main(void) {

    std::string entry = "asp12_i_ASP13";

    char *newArray = leaveLetters(entry);
    std::cout << newArray << std::endl;

    delete [] newArray;

    return EXIT_SUCCESS;
}