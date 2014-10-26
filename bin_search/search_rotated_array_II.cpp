#include<iostream>
using namespace std;
//If sorted element contains duplicate element

bool search(int A[], int n, int key) {
    int start = 0, end = n - 1;

    while (start  <= end) {
        
        int mid = start + (end - start )/2;
        
        if (A[mid] == key) return true; //return m in Search in Rotated Array I

        if (A[start] < A[mid]) { //left half is sorted
            if (A[start] <= key && key < A[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        } else if (A[start] > A[mid]) { //right half is sorted
            
            if (A[mid] < key && key <= A[end])
                start = mid + 1;
            else
                end  = mid - 1;
        } else {
            start++; // search lineraly
        }
    }
    return false;
}


int main () {

    int A[] = {1} ;
    int n = sizeof(A)/sizeof(A[0]);
    bool ans = search (A,n,0); 
    if (ans == true) {
        cout << "element found." << endl;
    } else {
        cout << "element not found." << endl;
    }
}
