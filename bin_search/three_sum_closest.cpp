#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    //int min_sum = INT_MAX;
    int min_sum = 0;
    if (n <= 3) {
        for (int i=0;i<n;i++) {
            min_sum += num[i];
        }
    } else {
        sort(num.begin(),num.end());
        for (int i=0;i<3;i++) {
            min_sum += num[i];
        }
        for (int i=0;i<n-2;i++) {
            int a = num[i];
            int start_index = i+1;
            int end_index = n - 1;
            while (start_index < end_index) {
                int current_sum = a + num[start_index] + num[end_index];
                //Update sum
                //cout << current_sum  << endl;
                if ( current_sum == target) {
                    return current_sum;
                } else if ( abs(target-current_sum) < abs(target-min_sum) ) {
                    //min_sum = abs(target-current_sum);
                    min_sum = current_sum;
                }
                //Update the index
                if (current_sum > target) {
                    end_index--;
                } else {
                    start_index++;
                }
            }
        }
        
    }
    return min_sum;
}

int main () {
    int a[] = {-1,2,1,-4};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    int result = threeSumClosest(av,1);
    cout << "The closest sum = " << result << endl;
}
