#include<iostream>
#include<string>
using namespace std;


void string_split(string& s) {
    int n = s.length();
    for (int m=0 ;m<n;m++) {
        for (int d=0;d<n-1;d++) {
            for (int i=1;i<n-d;i++) {
                int j = i+ d;
                for (int k=i;k<=j;k++) {
                    cout << "(" << j << "," << k << ")" << endl;
                }
            }
        }
    }
}


int main () {
    string st = "safaricarrbi";

    string_split (st);
}
