#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//If increasing height move right else left
//Container with most water 
int maxArea(vector<int> &height) {
    int n = height.size();
    if (!n) {
        return n;
    }
    int start = 0;
    int end = n - 1;
    int max_area = INT_MIN;

    while (start <= end) {
        int min_ht = min(height[start],height[end] );
        int max_dist = (end - start);
        int area = min_ht * max_dist;
        max_area  = max(area,max_area);
        if (height[start] < height[end]) {
            start++;
        } else {
            end--;
        }
    }

    return max_area;
}


int main () {
   
   //int a[] = {1,2,1}; 
   int a[] = {1,2,4,3}; 
   vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
   int ans_ = maxArea (av);
   cout << "result = " << ans_ << endl;

}
