#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

//in case of palindrome there are 2 centers
//ABA,
//ABAD

//Given string find longest palindrome substring/longest palindorme subsequence
//ABADEA
bool isPalindrome(string input) {
    int end = input.length();
    if (end == 0) {
        return true;
    } 
    int start = 0;
    while (start < end) {
        if (input[--end] != input[start++]) {
            return false;
        }
    }
    return true;
}

string get_longest_palindrome (string input) {
    int maxLen = INT_MIN; 
    string resultStr = "";
    int n = input.length();
    //O(n^2)
    for (int i = n-1;i >= 2;i--) {
        for (int start = 0;start < n-i;start++) {
            int end = start + i - 1;
            //cout << " (" << start << "," << end << ")" << endl;
            string tmp = input.substr(start,end-start+1);
            if (isPalindrome(tmp) == true) {
                int tmp_len = tmp.length();
                if (maxLen < tmp_len) {
                    resultStr = tmp;
                    maxLen = tmp_len;
                }
                cout << "found palindrome" << tmp << endl;
            }
        }
    }
    cout << "max len ( " << maxLen << " ) " << resultStr << endl;
    return resultStr ;
}





int test (string input) {
   if (isPalindrome(input) == true)  { 
       cout <<  input << " is palindrome" << endl;
   } else {
       cout <<  input << " is not palindrome" << endl;
   }
}

int main () {
    //test ("ABA");
    //test ("AB");
    //test ("AABAA");
    
    string lp = get_longest_palindrome("abcbcbb");
    cout << lp << endl;

    //string t = "hhello";
    //int l = t.length();
    //cout << t[--l] << endl;
}
