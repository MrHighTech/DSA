#include <iostream>
#include <bits/stdc++.h>

class Record {

    int mealId;
    std::string name;

    public:
        void setMealId(int mealId) {
            this->mealId = mealId;
        }

        int getMealId() {
            return this->mealId;
        }

        void setName(std::string name) {
            this->name = name;
        }

        std::string getName() {
            return this->name;
        }

};

void Swap(Record &a, Record &b) {
    Record tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(Record records[], int n, char direction) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (direction == '0') {
                if (records[j + 1].getMealId() < records[j].getMealId()) {
                    //Swap(records[j], records[j + 1]);
                    std::swap(records[j], records[j + 1]);
                }
                continue;
            }

            if (direction == '1') {
                if (records[j + 1].getMealId() > records[j].getMealId()) {
                    //Swap(records[j], records[j + 1]);
                    std::swap(records[j], records[j + 1]);
                }
                continue;
            }
        }
    }
}

void print(Record records[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "Meal id " << records[i].getMealId() <<
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
        int mealId;
        std::string name;

        std::cout << "Enter meal id: ";
        std::cin >> mealId;
        std::cout << "Enter name: ";
        std::cin >> name;

        records[i].setMealId(mealId);
        records[i].setName(name);
    }

    std::cout << "Enter sort direction [0 - ascending | 1 - descending]: ";
    std::cin >> direction;

    print(records, n);
    std::cout << std::endl;

    BubbleSort(records, n, direction);

    print(records, n);

    return EXIT_SUCCESS;
}