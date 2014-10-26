#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string& str_input) {
    int start = 0;
    int end = str_input.length() - 1;
    while(start <= end) {
        if (str_input[start] == str_input[end]) {
            start += 1;
            end -= 1;
        } else {
            return false;
        }
    }
    return true;
}

vector< vector<string> > partition (string s) {

    vector< vector <string> > output;
    for (int i=0;i<s.length();i++) {
         
    }

    return output;

}

int main () {
    string input = "TNAMANT";
    bool ans = isPalindrome(input);
    if (ans == true) {
        cout << "string is palindrome." << endl;
    } else {
        cout << "string is not palindrome." << endl;
    }
}
