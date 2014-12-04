#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isScramble(string s1, string s2) {
    if(s1.length() != s2.length())  {
        return false;
    }
    if(s1 == s2)  { 
        return true; 
    }
    string s3 = s1;
    string s4 = s2;
    sort(s3.begin(),s3.end());
    sort(s4.begin(),s4.end());
    if(s3 != s4 )  { 
        return false; 
    }

    for(int i=1; i<s1.length(); i++) {
        if(isScramble(s1.substr(0,i), s2.substr(0,i)) 
                && isScramble(s1.substr(i), s2.substr(i))) {  
            return true; 
        }
        if(isScramble(s1.substr(0,i), s2.substr(s2.length()-i)) 
                && isScramble(s1.substr(i), s2.substr(0, s2.length()-i))) { 
            return true; 
        }
    }
    return false;
}

//bool isScramble(string s1, string s2) {
//               int len=s1.size();
//        bool dp[100][100][100]={false};
//        for (int i=len-1;i>=0;i--)
//            for (int j=len-1;j>=0;j--) {
//                dp[i][j][1]=(s1[i]==s2[j]);
//                for (int l=2;i+l<=len && j+l<=len;l++) {
//                    for (int n=1;n<l;n++) {
//                        dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
//                        dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
//                    }
//                }
//            }
//        return dp[0][0][len];
//}



int main () {
    string s1 = "b";
    string s2 = "a";
    bool ans = isScramble (s1,s2);
    if (true == ans) {
        cout << "the result is true";
    }
}


