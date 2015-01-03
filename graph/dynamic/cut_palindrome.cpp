#include<iostream>
#include<string>
using namespace std;


bool isPalindrome(string& input) {
    int end = input.size() - 1;
    int start = 0;
    while (start <= end) {
        if (input[end--] != input[start++]) {
            return false;
        }
    }
    return true;
}

//https://hkn.eecs.berkeley.edu/examfiles/cs170_fa04_mt2_sol.pdf

int mspDP (string s) {
    int m = s.length();
    bool P[m][m];
    int D[m+1];

    //init state and stage
    for (int i=0;i<=m;i++) {
        D[i] = m-i;
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
            P[i][j] = false;
        }
    }
    //cout << "n DP" << endl;
    for (int i=m-1;i>=0;i--) {
        for (int j=i;j<m;j++) {
            if (s[i] == s[j] && (j-i == 1 || P[i+1][j-1] ) ) {
                P[i][j] = true;
                //current D[i] with add one as found new split
                D[i] = min (D[i],D[j+1]+1);
            }
        }
    }
    return D[0] - 1;
}

//Find the palindromes of 
int msp(string s) {
    if (isPalindrome(s)) {
        return 1;
    } else {
        int min_size = s.size() - 1;
        for (int i=1;i<s.size();i++) {
            min_size = min ( (msp(s.substr(0,i)) + msp(s.substr(i,s.size() - i))),min_size );
        }
        return min_size;
    }
}

int main () {
    string input = "aabcd";
    //string input = "abcd";
    int result = msp(input);
    cout << "the palindrome result = " <<  result << endl;
    result = mspDP(input);
    cout << "the palindrome result = " <<  result << endl;
}

