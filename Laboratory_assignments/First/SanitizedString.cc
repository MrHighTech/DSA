#include <iostream>

using namespace std;

bool isAlpha(char chr) {
    return chr >= 'a' && chr <= 'z' || chr >= 'A' && chr <= 'Z' || chr == ' ';
}

// M12ir213"!#"!#!$k"000o
class SanitizedString {
    string str;
    public:
        void removeDuplicateWhiteSpace() {
            char *newStr = (char *) malloc(this->str.size());
            int writtenLetters = 0;
            for (int i = 0; i < this->str.size(); ++i) {
                if (this->str[i] == ' ' && this->str[i - 1] == ' ') {
                    continue;
                }
                newStr[writtenLetters++] = this->str[i];
            }

            for (int i = 0; i < writtenLetters; ++i) {
                this->str[i] = newStr[i];
            }
            for (int i = writtenLetters; i < this->str.size(); ++i) {
                this->str[i] = '\0';
            }

            free(newStr);
        }
        void removeNonAlphaChars() {
            char *newStr = (char *) malloc(this->str.size());
            int writtenLetters = 0;
            for (int i = 0; i < this->str.size(); ++i) {
                if (isAlpha(this->str[i])) {
                    newStr[writtenLetters++] = this->str[i];
                }
            }
            newStr[writtenLetters++] = '\0';

            for (int i = 0; i < writtenLetters; ++i) {
                this->str[i] = newStr[i];
            }
            for (int i = writtenLetters; i < this->str.size(); ++i) {
                this->str[i] = '\0';
            }

            free(newStr);
        }
        SanitizedString() {}
        SanitizedString(string str) : str(str) {}
        ~SanitizedString() {}
        friend ostream &operator <<(ostream &o, SanitizedString ss) {
            o << ss.str;
            return o;
        }
};

int main(void) {

    string in;
    cout << "Insert string: ";
    getline(cin, in);

    SanitizedString ss(in);

    cout << ss << endl;

    ss.removeDuplicateWhiteSpace();
    ss.removeNonAlphaChars();

    cout << ss << endl;

    return EXIT_SUCCESS;
}