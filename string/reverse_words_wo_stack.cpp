#include<iostream>
#include<string>
using namespace std;

void reverseWords(string &s) {
    int len = s.length();
    string res = "";
    int i = len - 1;
    int start = i;
    int end = i;
    while (i>=0) {
        if (s[i--] != ' ') {
            start = i+1;
            //i<0 : to add last space
            if ( (i>=0) && (s[i] == ' ') || i < 0  ) {
                //i >= 0 : if only one character
                res += s.substr(start,end-start+1) + " " ;
                //To remove the space 
                end = start - 1;
            }
        } else {
            end--;
        }

    }
    s = res.substr(0,res.length()-1);
}

int main () {
    string st = "the sky is blue";
    reverseWords (st);
    cout << "the rev st = " << st << endl;

}
