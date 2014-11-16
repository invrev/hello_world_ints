#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<limits.h>
using namespace std;

string minWindow(string S, string T) {
    int m = S.length();
    int n = T.length();
    //O(m*log n) solution
    int min_window = INT_MAX;
    int min_start = 0;
    int min_end  = 0;
    int need_to_fill[256] = {0};
    queue <int> q[256];
    map<int,char> map_;

    for (int i=0;i<n;i++) {
        need_to_fill[T[i]]++;
    }
    //for (int i=0;i<256;i++) {
    //    if (need_to_fill[i] == 0) {
    //        need_to_fill[i] = -1;
    //    }
    //}
    for (int i=0;i<m;i++) {
        //Skip the the index from S if not present in T
        //if (need_to_fill[S[i]] == -1) {
        if (need_to_fill[S[i]] == 0) {
            continue;
        }
       //For duplicate chars in T 
        if (q[S[i]].size() < need_to_fill[S[i]]) {
            //Add index to queue
            q[S[i]].push(i);
            map_[i] = S[i];
        } else {
            //Replace the index with latest index
            int idx_to_remove = q[S[i]].front();
            map<int,char>::iterator it = map_.find(idx_to_remove);
            map_.erase(it);
            q[S[i]].pop();
            q[S[i]].push(i);
            map_[i] = S[i];
        }
        //Check if we covered all chars from the string T
        if (map_.size() == n) {
            //Get the maximum and minimum element
            int end = map_.end()->first;
            int start = map_.begin()->first;
            int window_len = end-start + 1;
            cout << "(" << start << "," << end << ")" << endl;
            if (window_len < min_window) {
                min_window = window_len;
                min_start = start;
                min_end = end;
            }
        }

    }
 return S.substr(min_start,min_window);    
}

int main () {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    string out_= minWindow (s,t);
    cout << out_ << endl;

}
