#include <iostream>

template <class T>
class SinglyLinkedList {

    template <class X> struct ListElement {
        X data;
        ListElement<X> *next;
    };

    ListElement<T> *head = nullptr;

    public:
        // Insert sorted
        bool insert(T data) {
            ListElement<T> **p = &head;
            ListElement<T> *element = new (std::nothrow) ListElement<T>;

            if (nullptr == element) return false;

            element->data = data;
            element->next = nullptr;

            if (nullptr == *p || (*p)->data > data) {
                element->next = *p;
                *p = element;
                return true;
            }

            for (; (*p)->next && (*p)->next->data < data; p = &((*p)->next));

            element->next = (*p)->next;
            (*p)->next = element;

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

    SinglyLinkedList<int> l;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cout << "Enter element at index [" << i << "]: ";
        std::cin >> x;
        l.insert(x);
    }

    l.print();

    return EXIT_SUCCESS;
}