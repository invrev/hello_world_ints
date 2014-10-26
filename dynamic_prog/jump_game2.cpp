#include<iostream>
#include<vector>
using namespace std;

int jump(int A[],int n)
{
    if (n <= 1)
        return 0;
    vector<int> s(n);
    s[n-1] = 0;
    for (int k = n-2; k >= 0; --k) {
        for (size_t i=1; i <= A[k] && i < n-k; ++i) {
            s[k] = min(s[k], 1 + s[k+i]);
        }
    }
    return s[0];
}

int main () {

}
