#include<iostream>
using namespace std;

int binSearchPivot (int A[],int start,int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        cout << "binSearchPivot = " << mid << endl;
        if (A[mid-1] > A[mid] && A[mid] < A[mid+1] ) {
            return mid;
        } else if (A[mid] < A[mid+1]) {
            start = mid + 2;
        } else {
            end = mid - 1;
        }
    }
}

int binSearch (int A[],int start,int end,int key) {
    cout << "in binSearch s = " << start << " e = " << end << " k = " << key << endl;
    while (start <= end) {
        int mid = (start + end ) /2;
        if (A[mid] == key) {
            return (mid);
        } else if (A[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
//search in rotated sorted array
int search0(int A[], int n, int target) {
    if (n >= 3) {
        int pivot = binSearchPivot (A,0,n);
        cout << "The pivot_loc = " << pivot  << " pivot = " << A[pivot] << endl;
        int loc_ = binSearch (A,0,pivot,target);
        //cout << "loc = " << loc_ << endl;
        if (loc_ == -1) {
            int loc1_ = binSearch (A,pivot,n,target);
            //cout << "loc1 = " << loc1_ << endl;
            return loc1_;
        } 
        return loc_;
        
    } else {
        for (int i=0;i<n;i++) {
            if(A[i]== target) {
                return i;
            }
        }
        return -1;
    }
}

//search in rotated sorted array
int search(int a[], int n, int target) {
    int loc = -1;
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        //4,5,7
        //cout << "( " << start << "," << mid << "," << end << " )" << endl;
        if (a[mid] == target ) {
            return mid;
        } else if (a[start] <= a[mid]  ) { // for case {3,1} use <=
            //key is between start and mid
            //Use of <= think of situation where it is first element
            if ( a[start] <= target && target < a[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } //else if ( a[mid] < a[start]) {
        else {
            if (target > a[mid] && target <= a[end]) { //Use of <= think of situation where it is last element
                start = mid + 1;
            } else {
                end = mid  - 1;
            }
        }
    }
    return loc; 
}



int main () {
   int A[] = {4,5,6,7,0,1,2}; 
   //int A[] = {1,2}; 
   //int A[] = {3,5,1}; 
   //int A[] = {5,1,3}; 
   int n = sizeof(A)/sizeof (A[0]);
   int loc_ = search (A,n,0);
   cout << "loc = " << loc_ << endl;

}
