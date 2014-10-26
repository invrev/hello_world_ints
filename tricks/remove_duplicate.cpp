#include<iostream>
using namespace std;

int removeDuplicates1(int A[], int n) {
    if (n <= 1) {
        return n;
    }
    int i = 0;
    int prev = A[0];
    int movement = 0;
    while (i+1 < n) {
        i = i + 1;
        if (prev == A[i] ) {
            A[i] = A[i+1];
            cout << "in move" << endl;
            movement += 1;
        } 
        prev = A[i];
    }
    //last element
    //if (prev == A[n-1]) {
    //    A[n-1] = 0;
    //    cout << "p move" << endl;
    //    movement += 1;
    //}
    int new_len = (n-movement);
    cout << "The new len = " << n <<  " nl = " << new_len << endl;
    for (int i =0;i<n;i++) {
        cout << A[i] << ",";
    }
    cout << endl;
    return n;
}

int removeDuplicates(int A[], int n) {
   if (n <= 1){
       return n;
   }
   int pivot = 0;
   for (int i=1;i<n;i++) {
        //Mismatch
       if (A[pivot] != A[i]) {
            A[++pivot] = A[i];
       }
   }
   return pivot + 1;
}

int main () {

    int A[] = {1,1};
    int n = sizeof(A)/sizeof(A[0]);
    int n1 = removeDuplicates (A,n);

}
