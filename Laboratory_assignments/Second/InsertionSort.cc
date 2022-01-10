#include <iostream>

class Record {

    int postalCode;
    std::string name;

    public:
        void setMealId(int postalCode) {
            this->postalCode = postalCode;
        }

        int getMealId() {
            return this->postalCode;
        }

        void setName(std::string name) {
            this->name = name;
        }

        std::string getName() {
            return this->name;
        }
};

void InsertionSort(Record records[], int n, char direction) {
    if (direction == '0') {
        for (int i = 1; i < n; ++i) {
            Record recordKey = records[i];
            int j = i - 1;
            while (j >= 0 && records[j].getMealId() > recordKey.getMealId()) {
                records[j + 1] = records[j];
                --j;
            }
            records[j + 1] = recordKey;
        }

        return;
    }

    if (direction == '1') {
        for (int i = 1; i < n; ++i) {
            Record recordKey = records[i];
            int j = i - 1;
            while (j >= 0 && records[j].getMealId() < recordKey.getMealId()) {
                records[j + 1] = records[j];
                --j;
            }
            records[j + 1] = recordKey;
        }

        return;
    }
}

void print(Record records[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Postal code " << records[i].getMealId() <<
                     ", Name " << records[i].getName() << std::endl;
    }
}



int main(void) {

    int n;
    char direction;

    std::cout << "Enter n: ";
    std::cin >> n;

    Record records[n];

    for (int i = 0; i < n; ++i) {
        int postalCode;
        std::string name;

        std::cout << "Enter postal code: ";
        std::cin >> postalCode;
        std::cout << "Enter name: ";
        std::cin >> name;

        records[i].setMealId(postalCode);
        records[i].setName(name);
    }

    std::cout << "Enter sort direction [0 - ascending | 1 - descending]: ";
    std::cin >> direction;

    print(records, n);
    std::cout << std::endl;

    InsertionSort(records, n, direction);

    print(records, n);

    return EXIT_SUCCESS;
}