#include <iostream>

template <class T>
class DoublyLinkedList {

    template <class X> struct ListElement {
        X data;
        ListElement<X> *next;
        ListElement<X> *prev;
    };

    ListElement<T> *head = nullptr;

    public:
        bool insert(T data) {
            ListElement<T> *element = new (std::nothrow) ListElement<T>;

            if (nullptr == element) return false;
            element->data = data;
            element->next = nullptr;

            if (nullptr == head) {
                head = element;
                element->prev = nullptr;
                return true;
            }

            ListElement<T> *p = head;

            for (; p->next; p = p->next);
            p->next = element;
            element->prev = p;
            return true;
        }

        void print() {
            for (ListElement<T> *tmp = head; tmp; tmp = tmp->next) {
                std::cout << tmp->data << " ";
            }
            std::cout << std::endl;
        }
};

int main(void) {

    int n;
    std::cout << "Enter how many elements you want to insert: ";
    std::cin >> n;

    DoublyLinkedList<std::string> l;
    for (int i = 0; i < n; ++i) {
        std::string x;

        std::cout << "Enter element at index [" << i << "]: ";
        std::cin >> x;

        l.insert(x);
    }

    l.print();

    return EXIT_SUCCESS;
}