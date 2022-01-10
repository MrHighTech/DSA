#include <iostream>
#define STACK_SIZE 10


class Stack {

    int stack[STACK_SIZE] = {0};
    int top = -1;

    public:
        bool push(int item) {
            if (top + 1 >= STACK_SIZE) return false;

            stack[++top] = item;

            return true;
        }

        bool pop(int &item) {
            if (top < 0) return false;

            item = stack[top--];

            return true;
        }

        void print() {
            for (int i = 0; i <= top; ++i) {
                std::cout << stack[i] << std::endl;
            }
        }

};

int main(void) {

    srand(time(nullptr));

    Stack s;

    for (int i = 0; i < STACK_SIZE; ++i) {
        int num = rand() % 10 + 1;
        s.push(num);
        std::cout << num << std::endl;
    }
    std::cout << std::endl;

    s.print();

    return EXIT_SUCCESS;
}