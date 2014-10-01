#include<iostream>
#include<vector>
using namespace std;

//search for range
vector<int> searchRange(int A[], int n, int target) {
    //perform iterative search
    int start = 0;
    int end = n;
    vector<int> result(2);
    result[0] = -1;
    result[1] = -1;
    while (start <= end) {
       int mid = (start + end) / 2;
       cout << "mid = " << mid << " A[mid] = " << A[mid] << endl;
       if (A[mid] == target) {
            int left = mid;
            int right = mid ;
            for (int i=mid;i>= 0;i--){
            //for (int i=mid;i>= start;i--){
                if (A[i] != target) {
                    break;
                }
                left = i;
            }
            result[0] = left;
            for (int i=mid;i<n;i++) {
            //for (int i=mid;i<end;i++) {
                if (A[i] != target) {
                    break;
                }
                right = i;
            }
            result[1] = right;
            //cout << "( " << left << "," << right << " )"  << endl;
            return result;
       } else if (A[mid] < target) {
            start = mid + 1;
       } else {
           end = mid - 1;
       }
    }
    return result;
}


int main () {
    //int A[] = {5, 7, 7, 8, 8, 10};
    int A[] = {1,3};
    int n = sizeof(A)/sizeof(A[0]);
    vector<int> result = searchRange(A,n,1);
    cout << "[ " << result[0] << "," << result[1] << " ]"  << endl;
}
