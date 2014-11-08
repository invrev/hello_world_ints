#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/**
  Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
  For example,
  Given:
  s1 = "aabcc",
  s2 = "dbbca",
  When s3 = "aadbbcbcac", return true.
  When s3 = "aadbbbaccc", return false.
**/

bool is_interleaving_rec (string s1,string s2,string s3) {
    cout << "is_interleaving_rec s1 = " << s1 << " s2=" << s2 << " s3= "<< s3 << endl;
    int s1_len = s1.length();
    int s2_len = s2.length();
    if (s1_len == 0 && s2_len == 0) {
        return true;
    } else {
        return ( s1[0] == s3[0] 
                && 
                //Delete the character from s1 and s3
                is_interleaving_rec(s1.substr(1,s1.length()-1),s2,s3.substr(1,s3.length()-1)) 
                || 
                s2[0] == s3[0] 
                && 
                //Delete character from s2 and s3
                is_interleaving_rec(s1,s2.substr(1,s2.length()-1),s3.substr(1,s3.length()-1))); 
    }

}

void print_result (bool result,string s1,string s2,string s3) {
    if (result == true) {
        cout << "interleaving found in s3 = " << s3 << " from s1 = " << s1 << " from s2 = " << s2 << endl;
    } else {
        cout << "interleaving not found in s3 = " << s3 << " from s1 = " << s1 << " from s2 = " << s2 << endl;
    }

}


int main () {

    bool result = is_interleaving_rec ("aabcc","dbbca","aadbbcbcac");
    print_result (result,"aabcc","dbbca","aadbbcbcac");

    result = is_interleaving_rec ("aabcc","dbbca","aadbbbaccc");
    print_result (result,"aabcc","dbbca","aadbbbaccc");

}
