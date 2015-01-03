#include<iostream>
#include<string>
using namespace std;

//Identify stage,state,value and recursion

//string interleaving
//eg a="ab" b="bc"  c="abcb"
//Think recursively either in forward or backward direction
//first char of C must come from start of A or start of B
//ll'y last char of C must come from last char of A or B

bool is_interleaving_rec (string a,string b,string c) {
    int m = a.length();
    int n = b.length();
    int p = c.length();
    //problem is m and n are of lenght 0
    if ( (m+n) != p) {
        return false;
    } 
    //To check the empty strings
    if (m == 0 && n == 0 && p == 0 ) {
        return true;
    }
    else {
        return ( (a[0] == c[0]) && is_interleaving_rec(a.substr(1,a.length()-1),b,c.substr(1,c.length()-1)) )
            || ( (b[0] == c[0] ) && is_interleaving_rec(a,b.substr(1,b.length()-1),c.substr(1,c.length() -1)) )  ;
    }
}

bool is_interleaving_dp (string a,string b,string c) {
    int m = a.length();
    int n = b.length();
    int p = c.length ();
    if ( (m+n) != p ) {
        return false;
    }
    
    bool sv[m+1][n+1];
    sv[0][0] = true;
    //init stage
    for (int i=1;i<=m;i++) {
        sv[i][0] = (a[i-1] == c[i-1]) ;
    }

    //init state
    for (int j=1;j<=n;j++) {
        sv[0][j] = (b[j-1] == c[j-1]);
    }
    //compute value
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            //Think from back (m+n-1)
            //cout << " ( " << a[i-1] << "," << b[j-1] << " , "<< c[i+j-1] << endl;
            if ( c[i+j-1] == a[i-1] || c[i+j-1] != b[j-1]) {
                // Current character of C matches with A 
                sv[i][j] = sv[i-1][j];
            } else if ( c[i+j-1] != a[i-1] && c[i+j-1] == b[j-1]) {
                // Current character of C matches with B
                sv[i][j] = sv[i][j-1];
            } else if (c[i+j-1] == a[i-1] && c[i+j-1] == b[j-1]) {
                // Current character of C matches with that of both A and B
                sv[i][j] = sv[i][j-1] || sv[i][j-1];
            }
        }
    }


    for (int i=0;i<=m;i++)  {
        for (int j=0;j<=n;j++) {
            cout << sv[i][j] << " ";
        }
        cout << endl;
    }

    return sv[m][n];


}




void test (string a,string b,string c) {
    if (is_interleaving_rec(a,b,c)) {
        cout << "string a = " << a << " and b = " << b << " are interleaving " << endl;
    } else {
        cout << "string a = " << a << " and b = " << b << " are not interleaving." << endl;
    }
    if (is_interleaving_dp(a,b,c)) {
        cout << "string a = " << a << " and b = " << b << " are interleaving " << endl;
    } else {
        cout << "string a = " << a << " and b = " << b << " are not interleaving." << endl;
    }
}


int main () {

    test("ab", "bc", "abbc");
    test("ab", "bc", "abcb");
    //test("XXY", "XXZ", "XXZXXXY");
    //test("XY" ,"WZ" ,"WZXY");
    //test ("XY", "X", "XXY");
    //test ("YX", "X", "XXY");
    //test ("XXY", "XXZ", "XXXXZY");
}



