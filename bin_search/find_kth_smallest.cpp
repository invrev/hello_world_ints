#include<iostream>


int find_kth_maximum(vector<int>& num,int k) {
   
    int start = 0;
    int end = num.size() - 1;

    int p = parition(num,start,end);
    if (p > k) {
        //search p -1
    } else if (p < k) {
        //search from p+1
    } else {
        return num[p];
    }

}

int main () {

}
