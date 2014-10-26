#include<iostream>
using namespace std;


int sqrt (int x) {
    if (x == 0 || x == 1) {
        return x;
    } else {
        int start = 1;
        int end = x;
        int prevMid = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            //mid*mid == x
            if (mid == x/mid ) {
                return mid;
            } else if (mid > x/mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
                prevMid = mid;
            }
        }
        return prevMid;
    }
}

int main () { 
    int x = 5;
    int ans = sqrt(x);
    cout << "the ans = " << ans << endl;
}

