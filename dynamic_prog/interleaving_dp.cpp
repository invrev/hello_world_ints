#include<iostream>
#include<string>
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



//DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position, and s2 is at jth position. 0th position means empty string.
//
//So if both s1 and s2 is currently empty, s3 is empty too, and it is considered interleaving. If only s1 is empty, then if previous s2 position is interleaving and current s2 position char is equal to s3 current position char, it is considered interleaving. similar idea applies to when s2 is empty. when both s1 and s2 is not empty, then if we arrive i, j from i-1, j, then if i-1,j is already interleaving and i and current s3 position equal, it s interleaving. If we arrive i,j from i, j-1, then if i, j-1 is already interleaving and j and current s3 position equal. it is interleaving.
//
bool is_interleave_dp (string s1,string s2,string s3) {
    int m = s1.length();
    int n = s2.length();
    if (m+n != s3.length()) {
        return false;
    }
    //initialize
    bool solution_vector[m+1][n+1];
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=n;j++) {
            solution_vector[i][j] = false;
        }
    }
    //solution_vector[0][0] = true;
    for (int i = 0;i<=m;i++) {
        //solution_vector[++i][0] = false;
        for (int j = 0;j<=n;j++) {
            if (i == 0 && j == 0) {
                solution_vector[i][j] = true;
            }
            else if (i == 0 && s2[j-1] == s3[j-1] ) {
                solution_vector[i][j] = solution_vector[i][j-1];
            }
            else if (j == 0 && s1[i-1] == s3[i-1]) {
                solution_vector[i][j] = solution_vector[i-1][j];
            }
            else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) {
                solution_vector[i][j] = solution_vector[i-1][j] ;
            }
            else if (s1[i-1] != s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                solution_vector[i][j] = solution_vector[i][j-1] ;
            }
            else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]) {
                solution_vector[i][j] = (solution_vector[i-1][j] || solution_vector[i][j-1]);
            }
        }
    }
    return solution_vector[m][n];
}


int main () {
    bool result = is_interleave_dp ("aabcc","dbbca","aadbbcbcac");
    cout << "result = " << result  << endl;
    result = is_interleave_dp ("aabcc","dbbca","aadbbbaccc");
    cout << "result = " << result  << endl;
}
