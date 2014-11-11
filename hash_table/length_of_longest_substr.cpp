#include<iostream>
#include<string>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int opt[256] ;
    for (int i=0;i<256;i++) {
        opt[256] = -1; //As index start from 0 and opt stores the index
    }
    int end = s.length();
    int start = 0;
    int max_len = 0;
    int char_index_max = 0;
    while (start < end) {
        char_index_max = max(char_index_max ,opt[s[start]] + 1); //case bb
        opt[s[start]] = start;
        max_len = max(max_len,start-char_index_max+1);
        start++;
    }
    return (max_len);
}

//Failed test case
//wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco
int lengthOfLongestSubstring_fail (string s) {
    bool char_arr[256] = {false};
    int end = s.length();
    int start = 0;
    int max_len = 0;
    int tmp_len = 0;
    while (start < end) {
        if (char_arr[s[start]] == false) {
            char_arr[s[start]] = true;
            tmp_len++;
        } else {
            tmp_len = 0;
        }
        max_len = max(max_len,tmp_len);
        start++;
    }
    return (max_len);
}

int main () {

    string st1 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    //string st = "abcabc";
    //string st = "bbbbbb";
    string st = "abcabcbb";
    int l = lengthOfLongestSubstring (st1);
    cout << "the len = " << l << endl;

    string st2 = "a";
    l = lengthOfLongestSubstring (st2);
    cout << "the len = " << l << endl;
}



