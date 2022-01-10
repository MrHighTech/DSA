#include <iostream>

template <class T>
class QueueList {

    template <class X> struct QueueElement {
        X data;
        QueueElement<X> *next;
    };

    QueueElement<T> *head = nullptr;
    QueueElement<T> *tail = nullptr;

    public:
        QueueList() {}

        bool enqueue(T data) {
            QueueElement<T> *element = new (std::nothrow) QueueElement<T>();

            if (nullptr == element) {
                return false;
            }

            element->data = data;
            element->next = nullptr;

            if (nullptr == head) {
                head = element;
                tail = element;
                return true;
            }

            tail->next = element;
            tail = element;

            return true;
        }

        bool dequeue(T &data) {
            if (nullptr == head) {
                return false;
            }

            data = head->data;
            QueueElement<T> *p = head;
            head = head->next;
            delete p;

            return true;
        }
};

int main(void) {

    int n, tmp;
    QueueList<int> q;

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