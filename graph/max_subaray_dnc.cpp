#include<iostream>
#include<limits.h>
using namespace std;

/*
"Find the contiguous subarray within an array 
(containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6."

What if we changed this 1-d array to 2-d array.

http://www.cosc.canterbury.ac.nz/tad.takaoka/cats02.pdf

Kadane won't work in case of 2-d array
find maximum subarray from the 2-d array
    -1  2  -3  5 -4 -8  3 -3
    2  -4  -6 -8  2 -5  4  1
    3  -2  9  -9  3  6 -5  2
    1  -3  5  -7  8 -2  2 -6

*/
int find_max_sum  (int arr[],int start,int end) {
    for (int i=0;i< end;i++) {
        int tmp = arr[start] + arr[end];
    }
}

int find_max_subarray_with_d_and_c (int arr[],int start,int mid,int end) {
        int tmp_sum = 0;
        int left_sum = 0;
        int right_sum = 0;
        int cross_max = 0;

        //Note as we are finding the maximum subarray over the crossing 
        //so we have to traver in reverese
        for (int i=mid ;i >=0 ;i--){
            tmp_sum += arr[i];
            if (tmp_sum > left_sum) {
                left_sum = tmp_sum;
            }
        }
        tmp_sum = 0;
        for (int j= mid+1;j<end;j++) {
            tmp_sum += arr[j];
            if (right_sum > tmp_sum) {
                right_sum = tmp_sum;
            }
        }
        //find the maximum
        int max = left_sum;
        cross_max = left_sum + right_sum;
        if (cross_max < left_sum ) {
            cross_max = left_sum;
        } if (cross_max < right_sum) {
            cross_max = right_sum;
        }
        cout << "Returing max sum = " << cross_max << endl;
        return (cross_max);
}

static int max_sum = -999;

int find_max_subarray_divide (int arr[],int start,int end) {
    int left_max,right_max,cross_max;
    if (start == end) {
        return arr[start];
    } else if (start < end) {
        int mid = (start + end) / 2;
        left_max = find_max_subarray_divide (arr,start,mid);
        right_max = find_max_subarray_divide (arr,mid+1,end);
        cross_max = find_max_subarray_with_d_and_c (arr,start,mid,end);
        cout << "left_max = " << left_max << " right_max = " << right_max << " cross_max = "<< cross_max << endl;
        if (max_sum < cross_max)  {
            max_sum = cross_max;
        }
        return max_sum ;
    }
}

//MAX[i+1]  = MAX[i] + A[i]   (MAX[i] + A[i] > 0)
//          = 0 (MAX[i] + A[i] < 0)
int find_max_subarray (int arr[],int len) {
    int max_sum = INT_MIN;
    int temp_sum = 0;
    for (int i=0;i<len;i++) {
        temp_sum += arr[i];
        if (temp_sum < 0) {
            temp_sum = 0;
        }
        if (temp_sum > max_sum) {
            max_sum = temp_sum;
        }
    }
    cout << "maximum sum = " << max_sum << endl;

}

int main () {
    int arr [] = {-2,1,-3,4,-1,2,1,-5,4};
    find_max_subarray (arr,9);
    int last_ans = find_max_subarray_divide (arr,0,9);
    cout << "the output " << last_ans << endl;
}
