#include<iostream>
using namespace std;

void sortColors(int A[], int n) {
        int c[] = {0,0,0};

        for (int i=0;i<n;i++) {
            c[A[i]] = c[A[i]] + 1;   
        }
        for (int i=0;i<3;i++) {
            c[i] += c[i-1]; 
        }
        int b[n];
        for (int i=n-1;i>=0;i--) {  //This line provides the stability to counting sort
            //A[i] : get content
            //c[A[i]] - 1 : get the index of content
            //c[A[i]] - 1 : Reduce # of elements
            b[c[A[i]] - 1] = A[i];
            c[A[i]] = c[A[i]] - 1;
        }
        for (int i=0;i<n;i++) {
            cout << b[i] << " ";
        }
        cout << endl;
}

int main () {
    int a[] = {1,2,1};
    sortColors(a,3);
}
