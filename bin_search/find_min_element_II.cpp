#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &num) {
    int start = 0;
    int end = num.size() - 1;
    while (start < end) {
        if (num[start] < num[end]) {
            return num[start];
        }
        int mid = start + (end - start )/2;
        if (num[mid] > num[end] ) {
            start = mid + 1;
        } else if (num[mid] < num[start]) {
            end = mid;
        }
        else { // A[start] == A[mid] == A[end]
            start++;
        }
    }
    return num[start];
}

int main () {

    int a[] = {};
    vector <int> av(a,a+sizeof(a)/sizeof(a[0]));
    int ans = findMin(av);
    cout << "the min result = " << ans;

}
