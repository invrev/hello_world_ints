#include<iostream>
using namespace std;

int main () {
    string t = "2345";
    int len = t.length();
    for (int i=0;i<len;i++) {
        int t1 = t[i] - '0';
        cout << t1 << " ";
    }
    cout << endl;
}
