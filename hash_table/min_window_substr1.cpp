#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<limits.h>
using namespace std;


//Clever use of data structure
//2 Map (need_to_fill,has_found)  ,2 index pointer (start,end) , 1 variable : to maintan accounting
//need_to_fill : keeps track of Chars in T 
//has_found : keeps track of Chars in both S and T
//always move the end pointer
//And adjust the start pointer after completiion
//Handles the duplicate chars in T

string minWindow(string S, string T) {
    int m = S.length();
    int n = T.length();
    //O(m*log n) solution
    int min_window = INT_MAX;
    int min_start = 0;
    int min_end  = 0;
    int count = 0;
    int need_to_fill[256] = {0};
    int has_found[256] = {0};
    for (int i=0;i<n;i++) {
        need_to_fill[T[i]]++;
    }
    
    for (int start=0,end=0;end < m;end++) {
        if (need_to_fill[S[end]] == 0) {
            continue;
        }
        has_found[S[end]]++;
        if (has_found[S[end]] <= need_to_fill[S[end]]) {
            //Maintain how many chars vistied from T.
            count++;
        }
        if (count == n) {
            while (has_found[S[start]] > need_to_fill[S[start]] 
                    || need_to_fill[S[start]] == 0 )  {
                if (has_found[S[start]] > need_to_fill[S[start]] ) {
                    //update the count
                    has_found[S[start]]--;
                }
                //increment start
                start++;
            }
            int temp_min = end - start + 1;
            if (temp_min < min_window) {
                min_window = temp_min;
                min_start = start;
                min_end = end;
            }
        
        }
    }

    if (count != n) {
        string tmp = "";
        return tmp;
    }
    return S.substr(min_start,min_window);    
}

int main () {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    string out_= minWindow (s,t);
    cout << out_ << endl;

}
