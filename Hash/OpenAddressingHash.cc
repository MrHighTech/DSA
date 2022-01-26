#include <iostream>

class Hash {
    private:
        std::string *hash;
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
            this->hash = new std::string[n];
            this->n = n;
            for (int i = 0; i < n; ++i) {
                this->hash[i].clear();
            }
        }
        bool Add(std::string &s) {

            int index = this->HashFunction(s);
            for (int i = 0; i < this->n; ++i) {
                int address = (index + i) % this->n;
                if (!this->hash[address].empty()) {
                    this->hash[address] = s;
                    return true;
                }
            }

            return false;
        }
        bool Get(std::string &s) {
            int index = this->HashFunction(s);

            for (int i = 0; i < this->n; ++i) {
                int address = (index + i) % this->n;
                if (!this->hash[address].empty() && this->hash[address].compare(s)) {
                    return true;
                }
            }

            return false;
        }
        void Print() {
            for (int i = 0; i < this->n; ++i) {
                std::cout << this->hash[i] << std::endl;
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