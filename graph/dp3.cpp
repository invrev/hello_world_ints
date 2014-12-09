#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Think in different way LCS : longest common subsequence  (find maximum non overlapping lines)
//a,b.substr(1,b.length() - 1) : move the line from string b
//a.substr(1,a.length() - 1),b : move the line from string a
//a.substr(1,a.length() - 1),b.substr(1,b.length() - 1) : move the line from string a and string b
//This is reverse of edit distance
int get_lcs_length (string a,string b) {
    if (a.length() == 0 || b.length() == 0) {
        return 0;
    } else {
        //Think in different way LCS : longest common subsequence  (find maximum non overlapping lines)
        //a,b.substr(1,b.length() - 1) : move the line from string b
        //a.substr(1,a.length() - 1),b : move the line from string a
        //a.substr(1,a.length() - 1),b.substr(1,b.length() - 1) : move the line from string a and string b
        int lcs_length = max ( get_lcs_length (a,b.substr(1,b.length() - 1)),get_lcs_length (a.substr(1,a.length() - 1),b) );
        lcs_length = max (lcs_length,get_lcs_length (a.substr(1,a.length() - 1)
                    ,b.substr(1,b.length() - 1)) + (a[0] == b[0] ? 1 : 0) );
        return lcs_length ;
    }
}

//http://www.ics.uci.edu/~eppstein/161/960229.html
//Space-efficient LCS:
int lcs_length(char * A, char * B,int m,int n) {
    vector <int>X(m);
    vector <int>Y(n);
	//allocate storage for one-dimensional arrays X and Y
    //state
    for (int i = m; i >= 0; i--) {
        //stage
        for (int j = n; j >= 0; j--) {
		if (A[i] == '\0' || B[j] == '\0') X[j] = 0;
		else if (A[i] == B[j]) X[j] = 1 + Y[j+1];
		else X[j] = max(Y[j], X[j+1]);
        }
        //Reuse the calculated result for the next iteration.
        Y = X;
    }
    return X[0];
}

int get_lcs_length_dp (string a,string b) {
    int m = a.length();
    int n = b.length();
    int sv[m+1][n+1];
    //init stage
    for (int i = 0;i<=m;i++) {
        sv[i][0] = 0;
    }
    //init state
    for (int j=0;j<=n;j++) {
        sv[0][j] = 0;
    }
    //compute value
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int max_lcs = max(sv[i-1][j],sv[i][j-1]);
            //max_lcs = max(max_lcs,sv[i-1][j-1]);
            if (a[i-1] == b[j-1]) {
                //sv[i][j] = max_lcs + 1;
                sv[i][j] = max(max_lcs,sv[i-1][j-1] + 1);
            } else {
                sv[i][j] = max_lcs;
            }
        }
    }
    return sv[m][n];
}


int main () {
    //Ans is 4
    string a = "AGGTAB";
    string b = "GXTXAYB";
    int l = get_lcs_length(a,b);
    cout << "the max lcs len = " << l << endl;
    l = get_lcs_length_dp(a,b);
    cout << "the max lcs len = " << l << endl;
}
