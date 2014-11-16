#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

string minWindow(string S, string T) {

    int m = S.length();
    int n = T.length();

    //O(n^2) solution
    int min_window = INT_MAX;
    int start = 0;
    int end = 0;
    int tmp_start = 0;
    int tmp_end = 0;
    for (int i=0;i<m;i++) {
        int k = 0;
        tmp_start = i; 
        for (int j=i;j<m;j++)  {
            //if (k == n) {
            //    break;
            //}
            for (int t = 0 ;t<n;t++) {
                if (S[j] == T[t]) {
                    k++;
                    tmp_end = j;
                }
            }
        }
        if (k == n) {
            if ( (tmp_end-tmp_start) < min_window ) {
                min_window  = (tmp_end-tmp_start);
                start = tmp_start;
                end = tmp_end;
            }
            //min_window = min(min_window, (tmp_end-tmp_start) );

        }
    }


    //cout << "The min len = " << min_window << endl;
    //cout << "(" << start << "," << end << ")" << endl;
    string op_ = S.substr(start, (end-start) + 1);
    return op_ ;

}

int main () {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    string out_= minWindow (s,t);
    cout << out_ << endl;


}
