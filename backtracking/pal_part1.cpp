#include<iostream>
#include<vector>
using namespace std;

//In this problem there are 2 subproblems 1.finding palindrome 2. finding the split
//


//If I get it right, each cut at i+j is calculated by scanning (i-j)'s minimum cut + 1 
//if s[i-j, i+j] is a palindrome. This code is awesome. I was thinking of Manacher's algorithm + DP but your code is wayyyy better.
int minCut(string s) {
    int n = s.size();
    vector<int> cut(n+1, 0);  // number of cuts for the first k characters
    for (int i = 0; i <= n; i++)  {
        cut[i] = i-1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) { // odd length palindrome
            cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);
        }
        for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) { // even length palindrome
            cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
    }
    return cut[n];
}

int is_palindrome (string& s,int i,int j) {
    cout << " ( " << i << "," << j << " ) " << endl;
    while (i <= j) {
        if (s[i++] != s[j--]) {
            return 0;
        }
    }
    return 1;
}


//define a function f(i, j) to denote the minimal number of 
//splits to partition the substring str[i:j] into a set of palindromes. 
//If the substring is a palindrome itself, we don’t have to split so f(i, j) is 0. 
//If the substring is not a palindrome, the substring is split between two characters k and k+1. 
//f(i, j)= f(i, k)+ f(k+1, j)+1 under such conditions. 
//Therefore, f(i, j) can be defined with the following equation:

int mincut0 (string s) {
    int t_len = s.length();
    int cost[t_len+1];
    cost[0] = 0; 
    for (int i=1;i<= t_len;i++) {
        cost[i] = cost[i-1] + 1;
        //int min = cost[i];
        //cout << "i=" << i << endl;
        for (int k = 1;k <= i-2; k++) {
            cost[i] = min (cost[i], (cost[k] + is_palindrome(s,k+1,i) ) );
            //int tmp_cost = cost[k] + is_palindrome(s,k+1,i); //Partion between k and k+1
            //if (tmp_cost < cost[i]) {
            //    cost[i] = tmp_cost;
            //}
        }
    }
    return cost[t_len];
}

int mincut1 (string s) {
    int t_len = s.length();
    bool p[t_len+1][t_len+1];
    p[1][1] = true;
    for (int j=2;j<=t_len;j++) {
        p[j][j] = true;
        p[j-1][j] = (s[j-1] == s[j]);
        for (int i = j-2;i >= 1;i--) { 
            p[i][j] = ( (s[i]==s[j]) && p[i+1][j-1] );
        }
    }

    int cost[t_len+1];
    cost[0] = 0; 
    for (int i=1;i<= t_len;i++) {
        cost[i] = cost[i-1] + 1;
        //int min = cost[i];
        //cout << "i=" << i << endl;
        for (int k = 1;k <= i-2; k++) {
            cost[i] = min (cost[i], (cost[k] + p[k+1][i]) );
            //int tmp_cost = cost[k] + is_palindrome(s,k+1,i); //Partion between k and k+1
            //if (tmp_cost < cost[i]) {
            //    cost[i] = tmp_cost;
            //}
        }
    }
    return cost[t_len];
}





int main () {
    //string s = "aabaaa";
    string s = "ababbbabbab";
    //string s = "aa";
    int min_cut = minCut (s);
    cout << "the min cut " << min_cut << endl;
    min_cut = mincut0 (s);
    cout << "the min cut " << min_cut << endl;
    min_cut = mincut1 (s);
    cout << "the min cut " << min_cut << endl;
}
