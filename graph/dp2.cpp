#include<iostream>
#include<string>
using namespace std;

int edit_distance_rec (string a,string b) {
   if (a.length() == 0)  {
       return b.length();
   } else if (b.length() == 0) {
       return a.length();
   }  else {
       int r = edit_distance_rec(a.substr(1,a.length()-1),b) + 1;
       int i = edit_distance_rec(a,b.substr(1,b.length()-1) ) + 1;
       int m = edit_distance_rec( a.substr(1,a.length()-1), b.substr(1,b.length()-1) ) + (a[0] == b[0] ? 0 : 1);
       int opt_min = min(r,i);
       opt_min = min(opt_min,m);
       return opt_min;
   }
}

int edit_distance_dp (string a,string b) {
    int m = a.length();
    int n = b.length();

    int sv[m+1][n+1];
    //init stages
    for (int i=0;i<=m;i++) {
        sv[i][0] = i;
    }

    //init states
    for (int j=0;j<=n;j++) {
        sv[0][j] = j;
    }

    //compute values
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            //cost of insert and delete 
            int opt = min (sv[i-1][j] + 1,sv[i][j-1] + 1) ;
            //cost of matching
            opt = min (opt,sv[i-1][j-1]);
            if (a[i-1] == b[j-1]) {
                sv[i][j] = opt;
            } else {
                sv[i][j] = opt + 1;
            }
        }
    }
    return sv[m][n];
}

int main () {
    string first = "ram";
    string second = "shyam";
    int d = edit_distance_rec (first,second);
    cout << "the min distance = " << d << endl;

    d = edit_distance_dp (first,second);
    cout << "the min distance = " << d << endl;
}
