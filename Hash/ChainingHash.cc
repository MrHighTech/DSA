#include <iostream>

template <typename T>
class HashElement {
    public:
        T item;
        HashElement<T> *next;
};

class Hash {
    private:
        HashElement<std::string> **hash;
        int n;
        int HashFunction(std::string &s) {
            int val = 0;
            for (char c : s) {
                val += c;
            }
            return val % this->n;
        }
    public:
        Hash(int n) {
            this->hash = new HashElement<std::string>*[n];
            this->n = n;
            for (int i = 0; i < n; ++i) {
                this->hash[i] = nullptr;
            }
        }
        bool Add(std::string &s) {
            HashElement<std::string> *newEl = new HashElement<std::string>();

            newEl->item = s;

            int index = this->HashFunction(s);
            newEl->next = this->hash[index];
            this->hash[index] = newEl;

            return true;
        }
        bool Get(std::string &s) {
            int index = this->HashFunction(s);
            HashElement<std::string> *tmp = this->hash[index];
            while(tmp) {
                if (tmp->item.compare(s) == 0) return true;
                tmp = tmp->next;
            }

            return false;
        }
        void Print() {
            for (int i = 0; i < this->n; ++i) {
                HashElement<std::string> *tmp = this->hash[i];
                std::cout << "[" << i << "] ";
                while(tmp) {
                    std::cout << tmp->item << " ";
                    tmp = tmp->next;
                }
                std::cout << std::endl;
            }
        }
};

int main(void) {

    Hash hash(10);
    std::string *names = new std::string[11] {"Mark", "John", "Claude", "Rock", "Will", "Hax", "Jops", "Trux", "Jake", "Roke", "Jack"};

    for (int i = 0; i < 10; ++i) {
        hash.Add(names[i]);
    }

    hash.Print();
    std::cout << hash.Get(names[6]) << std::endl;
    std::cout << hash.Get(names[10]) << std::endl;

    return EXIT_SUCCESS;
}