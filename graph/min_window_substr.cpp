#include<iostream>
#include<string>
#include<limits.h>
#include<cstring>
using namespace std;


//S = "ADOBECODEBANC"
//T = "ABC"  
//OP = "BANC"
//S is not necessary to be substring of T as chars from T might be scattered

//
string miniumWindowSubstring(string S,string T) {

    //start and end with min length
    int minLen = INT_MAX;
    int m = S.length();
    int n = T.length();
    int expected_match[256];
    int actual_match[256];
    int count = 0; 
    int start = 0;
    int min_start = 0;
    memset(expected_match,0,sizeof(expected_match[0]) * 256);
    memset(actual_match,0,sizeof(actual_match[0]) * 256);

    //To match scattered chars in S
    for (int i=0;i<n;i++) {
        expected_match[T[i]]++;
    }
    for (int end=0; end < m;end++) {
        if (expected_match[S[end]] == 0) {
            continue;
        }
        actual_match[S[end]]++;
        if(actual_match[S[end]] <= expected_match[S[end]] ) {
            //Get the first window
            count++;
        }
        if (count == n) {
            //adjust start move it forward and next successive window update the start
            while (expected_match[S[start]] == 0 || actual_match[S[start]] > expected_match[S[start]]) {
                if (actual_match[S[start]] > 0) {
                    actual_match[S[start]]--;
                }
                start++;
            }
            int tmp = end - start + 1;
            minLen = min(tmp,minLen);
            min_start= start;
        }
    }
    if (minLen == INT_MAX) {
        return "";
    }
    return S.substr(min_start,minLen);
}


int main () {
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string tmp = miniumWindowSubstring(S,T);
    cout << "min window substr match (" << S  << "," << T << ") =  " << tmp  << endl;

}
