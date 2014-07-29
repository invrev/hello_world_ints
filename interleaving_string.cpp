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


//This approach works only when s1 and s2 will have distinct characters
bool is_interleaving (string s1,string s2,string s3) {

    int s1_len = s1.length();
    int s2_len = s2.length();
    int s3_len = s3.length();
    if (s1_len + s2_len == s3_len) {
        //sort s1
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        sort(s3.begin(),s3.end());
        int j = 0;
        int k = 0;
        for (int i=0;i<s3_len;i++) {
            if (s3[i] == s1[j] && j < s1_len) {
                j = j + 1;
            } else if (s3[i] == s2[k] && k < s2_len) {
                k = k + 1;
            } else {
                return false;
            }
        }
        return (true);
    }
    return (false);
}

//This approach works only when s1 and s2 will have distinct characters
bool is_interleaving_v1 (string s1,string s2,string s3) {
    int s1_len = s1.length();
    int s2_len = s2.length();
    int s3_len = s3.length();
    int j = 0;
    int k = 0;
    if (s3_len == s1_len+s2_len) {
        for (int i=0;i<s3_len;i++)  {
            if (s3[i] == s1[j] && j < s1_len) {
                j = j + 1;
            } else if (s3[i] == s2[k] && k < s2_len) {
                k = k + 1;
            }
        }
        cout << "s1_len = " << j << ",s2_len = " << k << endl;
        if (j == s1_len && k == s2_len) {
            return true;
        }
        else  {
            return false;
        }
    }
    return false;
}

bool is_interleaving_dp (string s1,string s2,string s3) {
    int m = s1.length();
    int n = s2.length();
    int s3_len = s3.length();
    if (s3_len == m+n)  {
        //init the dp table
        bool dp[m+1][n+1];
        dp [m][n] = false;
        dp[0][0] = true;
        cout << "before " << dp[m][n] << endl;
        for (int i = 1;i <= (m);i++) {
            if (s3[i-1] == s1[i-1] ) { //&& dp[i-1][0]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        for (int j = 1;j<=n ;j++) {
            if (s3[j-1] == s2[j-1] ) {  //&& dp[0][j-1]) {
                dp[0][j] = true;
            } else {
                break;
            }
        }
        for (int i=1;i<= m;i++) {
            for (int j=1;j<=n;j++) {
                if ((s3[i+j-1] == s1[i-1]) && dp[i-1][j] 
                        || (s3[i+j-1] == s2[j-1]) && dp[i][j-1])  {
                    dp[i][j] = true;
                }
            }
        }
        cout << "after " << dp[m][n] << endl;
        return (dp[m][n]);
    } 
    return false;
}


//TODO : Trying toe achive result caching the single value not complete table
bool is_interleaving_dp_v1 (string s1,string s2,string s3) {
    int m = s1.length();
    int n = s2.length();
    int s3_len = s3.length();
    if (s3_len == m+n)  {
        bool is_prev_s1_match = false;
        bool is_prev_s2_match = false;
        //init
        if (s3[0] == s1[0]) {
            is_prev_s1_match = true;
        }
        if (s3[0] == s2[0]) {
            is_prev_s2_match = true;
        }
        for (int i=1,j=1,k=1;i<(m+n);i++) {
            if (s3[i] == s1[j] && s3[i-1] == s1[j-1] ) {
                is_prev_s1_match = true;
                j = j + 1;
            } if (s3[i] == s2[k] && s3[i-1] == s2[k-1] ) {
                is_prev_s2_match = true;
                k = k + 1;
            } else {
                return false;
            }

        }
        return true;
    } 
    return false;
}

bool is_interleaving_v3 (string s1,string s2,string s3) {
    cout << "is_interleaving_v3 s1 = " << s1 << " s2=" << s2 << " s3= "<< s3 << endl;
    int s1_len = s1.length();
    int s2_len = s2.length();
    if (s1_len == 0 && s2_len == 0) {
        return true;
    } else {
        //cout << "s1[0] = " << s1[0] << " s2[0] = " << s2[0] << " s3[0] = " << s3[0] << endl;
        //cout << "s1 = " << s1 << " s2="<< s2 << " s3=" << s3 << endl;
        return ( s1[0] == s3[0] && is_interleaving_v3(s1.substr(1,s1.length()-1),s2,s3.substr(1,s3.length()-1)) || 
               s2[0] == s3[0] && is_interleaving_v3(s1,s2.substr(1,s2.length()-1),s3.substr(1,s3.length()-1))); 
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
    //bool result = is_interleaving ("aabcc","dbbca","aadbbcbcac");
    //print_result (result,"aabcc","dbbca","aadbbcbcac");

    //result = is_interleaving ("aabcc","dbbca","aadbbbaccc");
    //print_result (result,"aabcc","dbbca","aadbbbaccc");

    //bool result = is_interleaving_v3 ("aabcc","dbbca","aadbbcbcac");
    //print_result (result,"aabcc","dbbca","aadbbcbcac");

    //result = is_interleaving_v3 ("aabcc","dbbca","aadbbbaccc");
    //print_result (result,"aabcc","dbbca","aadbbbaccc");


    bool result = is_interleaving_dp ("aabcc","dbbca","aadbbcbcac");
    print_result (result,"aabcc","dbbca","aadbbcbcac");

    result = is_interleaving_dp ("aabcc","dbbca","aadbbbaccc");
    print_result (result,"aabcc","dbbca","aadbbbaccc");

    result = is_interleaving_dp ("aabcc","dbbca","aadbbbaccd");
    print_result (result,"aabcc","dbbca","aadbbbaccd");

}
