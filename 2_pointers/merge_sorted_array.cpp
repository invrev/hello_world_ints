#include<iostream>
#include<vector>
using namespace std;

//The OOB solution start to compare from the last index of A and B
//Skiena Idea : used in Interleaving of the strings

void merge(int A[], int m, int B[], int n) {

    //int A[] = {1,2,8,10,15,0,0,0,0};
    //int B[] = {2,8,9,16};
    int a_idx = m-1;
    int b_idx = n-1;
    int tmp_idx = m+n - 1 ;
    while (a_idx >= 0 && b_idx >= 0 ) {
        if (A[a_idx] > B[b_idx] ) {
            A[tmp_idx--] = A[a_idx--];
        } else {
            A[tmp_idx--] = B[b_idx--];
        }
    }
    //Copy the remaining elements from B
    while (b_idx >= 0 ) {
        A[tmp_idx--] = B[b_idx--];
    }

    for (int i=0;i<m+n;i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


void merge0(int A[], int m, int B[], int n) {
    
    int a_idx = 0;
    int b_idx = 0;
    int tmp_idx = m+n - 1 ;
    while (m > a_idx && n > b_idx) {
        if (A[a_idx] <= B[b_idx] ) {
            a_idx++;
        } else {
            A[tmp_idx] = A[a_idx];
            A[a_idx] = B[b_idx];
            a_idx++;
            b_idx++;
            tmp_idx--;
        }
    }

    for (int i=0;i<m+n;i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main () {
    int A[] = {1,2,8,10,15,0,0,0,0};
    int B[] = {2,8,9,16};
    merge(A,5,B,4);
}


