#include <iostream>

template <class T>
class StackList {

    template <class X> struct StackElement {
        X data;
        StackElement<X> *next;
    };

    StackElement<T> *head = nullptr;

    public:
        StackList() {}

        bool push(T data) {
            StackElement<T> *element = new (std::nothrow) StackElement<T>();

            if (nullptr == element) {
                return false;
            }

            element->data = data;
            element->next = nullptr;

            if (nullptr == head) {
                head = element;
                return true;
            }

            element->next = head;
            head = element;

            return true;
        }

        bool pop(T &data) {

            if (nullptr == head) {
                return false;
            }

            StackElement<T> *tmp = head;
            data = head->data;
            head = head->next;

            delete tmp;
            return true;
        }

        void print() {
            int i = 0;
            for (StackElement<T> *p = head; p; p = p->next) {
                std::cout << "[" << i++ << "] " << p->data << std::endl;
            }
        }
};

int main(void) {

    srand(time(nullptr));
    StackList<int> s;

    for (int i = 0; i <= 101; ++i) {
        s.push(rand());
    }

    s.print();

    int data;

    while(s.pop(data)) {
        std::cout << data << std::endl;
    }

    return EXIT_SUCCESS;
}