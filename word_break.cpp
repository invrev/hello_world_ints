#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

bool wordBreak0(string s, unordered_set<string> &dict) {
     int dict_len = dict.size();
     string st = "";
     s = '#' + s + '#';
     int m = s.length();
     int start = 1;
     int end = 0;
     for (int i=1;i<m;i++) {
         string part = s.substr(start,i-start);
         //find element
         //cout << "B4_part = " << part << endl;
         if (dict.find(part) != dict.end())  {
             //cout << "part = " << part << endl;
             end = start + part.length();
             //start = i+1;
             start = i;
         }
     }
     //cout << "the pos = " << start << "," << m-1  << "," << end << endl;
     if (end == m-1 ) {
         //cout << "returing true" << endl;
         return true;
     }
     return false;
}


bool wordBreak1(string s, unordered_set<string> &dict) {
       string s2 = '#' + s;
       int len = s2.length();
       vector<bool> possible(len, false);
       possible[0] = true;
       for(int i = 1; i< len; i++) {
           for(int k=0; k<i; k++) {
               string temp = s2.substr(k+1, i-k);
               cout << "--" <<  temp << endl;
               cout << "i = " << i << ", k= " << k << "," << i-k << endl;
               if (dict.find(temp) != dict.end()) {
                   possible[i] = possible[k] ;
               }
               if(possible[i])  {
                   break;
               }
           }
       }
       return possible[len-1];
}


bool wordBreak(string s, unordered_set<string> &dict) {
    int len = s.size();
    bool* dp = new bool[len+1];
    memset(dp, false, len+1);
    dp[0] = true;
    for (int i = 1; i <= len;  ++i) {
        for (int j = 0; j <i; ++j) {
            if(dict.find(s.substr(j, i-j)) != dict.end() && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }             
    bool flag = dp[len];
    delete dp;
    return flag;  
}




int main () {
    unordered_set<string> split_dict ;
    //split_dict.insert("a");
    split_dict.insert("b");
    split_dict.insert("leet");
    split_dict.insert("code");
    split_dict.insert("aaaa");
    split_dict.insert("aaa");
    //bool ans = wordBreak ("ab",split_dict);
    //bool ans = wordBreak ("leetcode",split_dict);
    bool ans = wordBreak ("aaaaaaa",split_dict);
}

