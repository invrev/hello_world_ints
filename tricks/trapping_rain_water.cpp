#include<iostream>
#include<algorithm>
using namespace std;


int trap(int A[], int n) {
    if (n == 0) {
        return 0;
    }
    int trap_water = 0;
    int total_capacity = 0;
    int left_to_right_max[n];
    int right_to_left_max[n];

    //Traverse from left to right find max between ([k],[n-k])
    //Please NOTE : It is not the max between 2 consecutive elements like A[i],A[i+1]
    left_to_right_max[0] = A[0];
    for (int i=1;i<n;i++) {
        left_to_right_max[i] = max(A[i],left_to_right_max[i-1]);
    }

    //Traverse from right to left and pick the RIGHT MAXIMUM from ([n-k], and rest_of_array [k])
    right_to_left_max[n-1] = A[n-1];
    for (int i= n-2;i>=0;i--) {
        right_to_left_max[i] = max(A[i],right_to_left_max[i+1]);
    }

    //
    for (int i=0;i<n;i++) {
        total_capacity  += A[i];
        trap_water += min(right_to_left_max[i],left_to_right_max[i]);
    }
    return trap_water - total_capacity;
}

//Instead of storing the values in the array store in the variables left_max and right_max
//With O(C) space
int trap0 (int A[],int n) {

    if (!n) {
        return 0;
    }
    int start = 0;
    int end = n-1;
    
    //Think of case {1} with only 1 pillar
    int left_max = A[0];
    int right_max = A[n-1];
    int total_capacity  = left_max + right_max;
    int trap_water = total_capacity  ;
    
    while (start != end) {
        if (A[start] < A[end]) {
            start++;
            left_max = max(left_max,A[start]);
            trap_water += left_max;
            total_capacity += A[start];
        } else {
            end --;
            right_max = max(right_max,A[end]);
            trap_water += right_max;
            total_capacity += A[end];
        }
    }
    return trap_water - total_capacity ;

}

int main () {
    int a[] = {0,2,0};
    int n = sizeof(a)/sizeof(a[0]);
    cout << " trap =  " << trap(a,n) << endl;

}
