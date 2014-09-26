#include<iostream>
using namespace std;

void toh (int n,int a[],int b[],int c[]) {
    if (n > 0) {
        toh (n-1,a,b,c); 
        cout << "moving disk n = " << n << " disk # = " << a[n] << endl;
        int i = 0;
        while (c[i] != 0) {
            i += 1;
        }
        c[i] = a[n] ;
        toh(n-1,b,c,b); 
    }

}

int main () {
    int a[] = {4,3,2,1};
    int b [] = {0,0,0,0};
    int c [] = {0,0,0,0};
    toh(3,a,b,c);
}
