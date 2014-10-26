#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vec(vector<int>& num) {
    for (int i=0;i<num.size();i++){
        cout << num[i] << ",";
    }
    cout << endl;
}

//Other solution : space O(n),runtime O(n) use of hashmap

//O(nlogn) solution
int longestConsecutive (vector<int> &num) {
    sort(num.begin(),num.end());
    print_vec (num);
    int n = num.size();
    int prev = num[0];
    int len = 1,maxlen = 0;
    int i = 1;
    while (i < n) {
        if ( (num[i] - prev) == 1)  {
            len ++;
        } else {
            maxlen = max(len,maxlen);
            if ((num[i] - prev) !=  0 ) {
                len = 1;
            }
        }
        prev = num[i];
        i += 1;
    }
    //if ( (num[n-1] - prev) == 1 ) {
    //    len += 1;
    //}
    maxlen = max(len,maxlen);
    return maxlen;
}


int main () {
    //int a[] = {100,200,1,3,2,5};
    //9,1,4,7,3,-1,0,5,8,-1,6
    int a[] = { 9,1,4,7,3,-1,0,5,8,-1,6 };
    vector<int> num (a,a+sizeof(a)/sizeof(a[0]));
    int len = longestConsecutive(num);
    cout << "the length = "<< len << endl;
}
