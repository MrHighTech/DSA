#include <iostream>

#define QUEUE_SIZE 10

class Queue {
    int *queue;
    int size = 0;

    public:
        Queue() {
            queue = new int[QUEUE_SIZE];
        }

        ~Queue() {
            delete [] queue;
        }

        bool enqueue(int data) {
            if (size == QUEUE_SIZE) return false;

            queue[size++] = data;

            return true;
        }

        bool dequeue(int &data) {

            if (0 == size) return false;

            data = queue[0];
            for (int i = 0; i < size - 1; ++i) {
                queue[i] = queue[i + 1];
            }

            --size;

            return true;
        }

        void print() {
            for (int i = 0; i < size; ++i) {
                std::cout << queue[i] << std::endl;
            }
        }
};

int main(void) {

    int n, tmp;
    Queue q;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter number: ";
        std::cin >> tmp;
        q.enqueue(tmp);
    }

    while(q.dequeue(tmp)) {
        std::cout << tmp << std::endl;
    }

    return EXIT_SUCCESS;
}