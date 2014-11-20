#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &num) {

    int start = 0;
    int end = num.size() - 1;
    if (end == 0) {
        return num[start];
    }
    //while (start <= end) {
    while (start < end) {
        if (num[start] < num[end]) {
            return num[start];
        }
        int mid = start + (end-start) / 2;
        if (A[start] <= A[mid]) {
            start = mid + 1;
        } else if (A[start] > A[mid]) {
            end = mid;
        }
        
        //if (num[mid] >= num[start]) {
        //    start = mid + 1;
        //} else {
        //    //end = mid - 1;
        //    end = mid;
        //}
    }
    return num[start];
}

int main () {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> av(a,a+sizeof(a)/sizeof(a[0]));
    int min_ = findMin(av);
    cout << "the ans = " << min_ << endl;
}
