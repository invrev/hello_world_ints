#include<iostream>
#include<limits.h>
using namespace std;

//https://oj.leetcode.com/discuss/11174/share-my-iterative-solution-with-o-log-min-n-m
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    //Assum m < n 
    if (m > n) {
        return findMedianSortedArrays(B,n,A,m);
    }
    int k =  (n + m - 1)/2;
    int l = 0;
    int r = min (k,n);
    while (l < r) {
        int mid_a = (l + r)/2;
        int mid_b = k - mid_a;
        if (A[mid_a] < B[mid_b] ) {
            l = mid_a + 1;
        } else {
            r = mid_a;
        }
    }
    // after binary search, we almost get the median because it must be between
    // these 4 numbers: A[l-1], A[l], B[k-l], and B[k-l+1] 
    // if (n+m) is odd, the median is the larger one between A[l-1] and B[k-l].
    // and there are some corner cases we need to take care of.
    
    //int temp_a = INT_MIN;
    //int temp_a1 = INT_MIN ;
    //if (l > 0)  { 
    //    temp_a = A[l-1];
    //} 
    //if (k -l >= 0) {
    //    //cout << B[k-l] << endl;
    //    temp_a1 = B[k-l] ;
    //} 
    //int a = max(temp_a,temp_a1);
    int a = max(l > 0 ? A[l - 1] : INT_MIN, k - l >= 0 ? B[k - l] : INT_MIN);

    if (((n + m) & 1) == 1) {
        //cout << "RET " <<  a << endl;
        return (double) a;
    }
    // if (n+m) is even, the median can be calculated by 
    //      median = (max(A[l-1], B[k-l]) + min(A[l], B[k-l+1]) / 2.0
    // also, there are some corner cases to take care of.

    //int temp_b = INT_MAX;
    //int temp_b1 = INT_MAX;
    //if (l < n) {
    //    temp_b = A[l];
    //} 
    //if ( (k-l+1) < m ) {
    //    temp_b1 = B[k - l + 1] ;
    //} 
    //int b = min(temp_b,temp_b1);
    
    int b = min(l < n ? A[l] : INT_MAX, k - l + 1 < m ? B[k - l + 1] : INT_MAX);
    return (double) ((double) a + (double) b) / 2.0;
}


int main () {
    int A[] = {};
    int m = sizeof(A)/sizeof(A[0]);
    int B[] = {1};
    int n = sizeof(B)/sizeof(B[0]);
    double ans_ = findMedianSortedArrays (A,m,B,n);
    cout << "the result " << ans_ << endl;
}

