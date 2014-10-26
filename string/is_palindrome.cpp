#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isPalindrome(string s) {
    int end = s.length()-1;
    int start = 0;
    unordered_map<char,bool> u_map;
    u_map[' '] = true;
    u_map[':'] = true;
    u_map['.'] = true;
    u_map[','] = true;
    u_map['-'] = true;
    u_map['?'] = true;
    u_map['@'] = true;
    u_map['#'] = true;
    u_map['"'] = true;
    u_map['\''] = true;
    u_map[';'] = true;
    u_map['!'] = true;
    u_map['('] = true;
    u_map[')'] = true;
    u_map['`'] = true;

    while (start <= end) {
        //if (tolower (s[start]) == ' ' || tolower (s[start]) > ':') {
        if ( u_map.find (s[start]) != u_map.end() )  {
            //cout << "INC " << s[start] << endl;
            start++;
            continue;
        }
        //if (tolower (s[end]) < ' ' || tolower (s[end]) > ':') {
        if ( u_map.find (s[end]) != u_map.end() )  {
            end--;
            continue;
        }
        if (tolower(s[start]) == tolower(s[end]) ) {
            start++;
            end--;
        } else {
            return false;
        }
    }
    return true;
}

int main () {
    bool t = isPalindrome("::NAMAN:");
    if (t == true) {
        cout << "palindorme" << endl;
    } else {
        cout << "not palindrome" << endl;
    }
}
