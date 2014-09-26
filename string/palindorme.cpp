#include<iostream> 
#include<string>
using namespace std;
bool is_valid_char (string s,int index) {
        if ((tolower(s[index]) < 'a' || tolower(s[index])  > 'z')) {
            return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        cout << "string = " << s << endl;
        int start = 0;
        int end = s.length() - 1;
        while(start <= end) {
            if (!is_valid_char(s,start) ) {
                start += 1;
                cout << "start = " << start  << endl;
                continue;
            } if (!is_valid_char(s,end)) {
                end -= 1;
                cout << "end = " << start  << endl;
                continue;
            }
            if (tolower(s[start]) == tolower(s[end])) {
                start += 1;
                end -= 1;
            } else {
                return false;
            }
            
        }
        return true;
    }

void palindome_print (bool ans,string s) {
    if (ans == true) {
        cout << "palindorme = " << s << endl;
    } else {
        cout << "not palindome = " << s << endl;
    }
}

int main () {
    bool ans = isPalindrome("aaa");
    palindome_print (ans,"aaa");

    ans = isPalindrome("aa....aa");
    palindome_print (ans,"aa....aa");
}
