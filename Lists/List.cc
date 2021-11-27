#include <iostream>

template <class T> class List {
    template <class X> struct ListElement {
        X data;
        ListElement<X> *next;
    };

    ListElement<T> *head = nullptr;

    public:
        bool insert(T data) {
            ListElement<T> *element = new (std::nothrow) ListElement<T>;
            if (nullptr == element) return false;
            element->data = data;
            element->next = head;
            head = element;

            return true;
        }

        bool insert2(T data) {
            ListElement<T> **p = &head;
            ListElement<T> *element = new (std::nothrow) ListElement<T>;
            if (nullptr == element) return false;
            element->data = data;
            element->next = nullptr;

            for (; *p; p = &((*p)->next));

            *p = element;
            return true;
        }

        void printList() {
            for(ListElement<T> *ptr = head; ptr; ptr = ptr->next) {
                std::cout << ptr->data << " ";
            }

            std::cout << std::endl;
        }
};

int main(void) {


    List<int> l;
    l.insert2(4);
    l.insert2(5);
    l.insert2(6);
    l.insert(1);
    l.insert(2);
    l.insert(3);

    l.printList();

    return EXIT_SUCCESS;
}