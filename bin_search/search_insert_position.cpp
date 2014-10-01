#include<iostream>
#include<algorithm>
using namespace std;

int binSearch (int A[],int start,int end,int key) {
    if (start < end) {
        int mid = (start + end) / 2;
        if (A[mid] == key) {
            return mid;
        } else if (A[mid] < key) {
            binSearch (A,mid+1,end,key);
        } else {
            binSearch (A,start,mid-1,key);
        }
    } else {
        return -1;
    }
}

int insertbinSearch (int A[],int start,int end,int key,int end1) {
    //if (end1 < end) {
    if (start < end) {
        int mid = (start + end) / 2;
        if (A[mid] == key) {
            return mid;
        } else if  ( (A[mid-1] < key && key < A[mid+1]) ) {
            if (A[mid] <= key) {
                return mid + 1;
            } else {
                return mid ;
            }
        }
        else if (A[mid] < key) {
            insertbinSearch (A,mid+1,end,key,end1);
        } else {
            insertbinSearch (A,start,mid-1,key,end1);
        }
    } 
}


int searchInsert(int A[], int n, int target) {
    if (n >= 3) {
        //mid,mid-1,mid+1
        return (insertbinSearch(A,0,n,target,n));
    } else {
       //Do linear search 
        for (int i=0;i<n;i++) {
            //cout << "A[i] = " << A[i] << " target = " << target << endl;
            if (A[i] == target) {
                return i;
            }else if (A[i] > target) {
                return max(i--,0);
            }
        }
        return (n);
    }
}

int main () {
    int A[] = { 1,3 };
    int n = sizeof(A)/sizeof(A[0]);
    int pos = searchInsert (A,n,2);
    cout << "The insert position " << pos  << endl;
}
