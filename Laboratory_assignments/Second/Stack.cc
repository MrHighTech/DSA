#include <iostream>
#define MAX_SIZE 100

template <class T>
class Stack {

    private:
        int max;
        int top;
        T *stack;


    public:

        Stack() {
            this->max = MAX_SIZE;
            this->top = -1;
            this->stack = new T[max];
        }

        bool push(T item) {
            if (top + 1 >= max) return false;

            stack[++top] = item;

            return true;
        }

        bool pop(T &item) {
            if (top < 0) return false;

            item = stack[top--];

            return true;
        }

        void print() {
            for (int i = top; i > -1; --i) {
                std::cout << "[" << i << "] " << stack[i] << std::endl;
            }
        }
};

int main(void) {

    srand(time(nullptr));
    Stack<int> s;

    for (int i = 0; i <= 101; ++i) {
        s.push(rand());
    }

    s.print();

    return EXIT_FAILURE;
}