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
   if (n <= 2){
       return n;
   }
   int duplicate_upto = 1;
   for (int i=2;i<n;i++) {
        //Mismatch
       //Compare current element A[i] with last 2 elements
       if ( (A[duplicate_upto] != A[i]) || (A[duplicate_upto-1] != A[i]) ) {
           A[++duplicate_upto] = A[i];
       }
   }
   return (duplicate_upto + 1);
}

int main () {

    int A[] = {1,1,2,3,3,3,4};
    int n = sizeof(A)/sizeof(A[0]);
    int n1 = removeDuplicates (A,n);
    for (int i=0;i<n1;i++) {
        cout << A[i] << ",";
    }
    cout << endl;

}
