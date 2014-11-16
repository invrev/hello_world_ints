#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

//The assumption A[i] < n ,n = # of elements in the array
void do_swap (int& a,int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print_a (int a[],int n) {
    for (int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int A[],int n,int k=0) {
    int q = -1;
    for (int i=0;i<n;i++) {
        if (A[i] > k) {
            q++;
            do_swap(A[q],A[i]);
        }
    }
    return q;
}


//Idea : pigenhole principle
//If there are [0...k] index and [1..k+1] values then biggest missing positive # k+2 line # 62
//negative A[tmp-1] indicates the index(tmp-1) exists 
//First positive A[i] indicates missing +ve number

int firstMissingPositive(int A[], int n) {
    
    //print_a (A,n);
    int k = partition (A,n,0) + 1;
    //So out of k #'s need to find the missing positive element
    //out of [0,k] or [1,k+1] 1 positive number is missing.
    int missing_positive_number = k;
    for (int i=0;i<k;i++) {
        //Important to check the value for the index
        int tmp = abs(A[i]);
        if (tmp <= k ) {
            //NOTE : Always tmp > 0
            if (A[tmp-1] >= 0) {
                A[tmp-1] = -A[tmp-1];
            }
        }
    }

    for (int i=0;i<k;i++) {
        if (A[i] > 0 ) {
            missing_positive_number = i;
            return missing_positive_number + 1;
        }
    }

    return missing_positive_number + 1;
    //print_a (A,n);
    //return k;
}

int main () {
    int a[] = {3,4,-1,1,0};
    int n = sizeof(a)/sizeof(a[0]);
    int f = firstMissingPositive (a,n);
    cout << "First +ve # = " << f << endl;
}
