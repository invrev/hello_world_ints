#include<iostream>
#include<string>
#include<stack>
using namespace std;

void reverseWords(string &s) {
    int end = s.length() ;
    stack <string> str_stack;
    int start = 0;
    for (int i=0;i<end;i++) {
        int temp_end = i;
        if (s[i] == ' ') {
            while (s[i] == ' ') {
                i = i + 1;
            }
            //case : prefix spaces
            if (temp_end != 0) {
                str_stack.push(s.substr(start,temp_end-start));
            }
            start = i;
        }
    }
    //case : suffix spaces
    while (s[end-1] == ' ')  {
        end -= 1; 
    }
    str_stack.push(s.substr(start,end-start));
    s = ""; 
    while (!str_stack.empty()) {
        string tmp_str  = str_stack.top();
        s +=  tmp_str;
        s += " ";
        str_stack.pop();
    }
    
    cout << "s = " <<  s.length() << endl;
    s = s.substr(0,s.length() - 1);
    cout << "s =" <<  s << endl;
    cout << "s = " <<  s.length() << endl;
        
}

int main () {
    string s = "   blue   ";
    reverseWords (s);
}
