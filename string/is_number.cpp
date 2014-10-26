#include<iostream>
using namespace std;

bool isNumber(const char *s) {
    int i = 0;
    int no_of_unuseful_chars = 0;

    while (s[i] == ' ') {
        i++;
    }
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    if (s[i] <= '9' && s[i] >= '0') {
        i++;
    } else {
        return false;
    }

    return true;
}

int main () {
    char str[] = "123";
    bool ans = isNumber(str);
    if (ans == 1) {
        cout << str  << "is number " << endl;
    } else {
        cout << str  << "is not number " << endl;
    }

}
