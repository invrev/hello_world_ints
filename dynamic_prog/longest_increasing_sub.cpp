#include<iostream>
#include<vector>
using namespace std;

int get_lcs_length (int prev,int start,vector<int> input_sub) {
    if (input_sub.size() == start) {
        return 0;    
    }else {
        start += 1;
        int max = get_lcs_length (prev,start,input_sub);
        int current = start - 1;
        if (input_sub[current] > prev ) {  
            //If current input is part of subsequence
            int l = 1 + get_lcs_length (input_sub[current],start,input_sub);
            if (l > max) {
                max = l;
            }
        }
        return max; //if current is not part of input subsequence
    }
}

int main () {
    int a[] = {2,6,3,4,1,2,9,5,8};
    vector<int> vec_a(a,a+sizeof(a)/sizeof(a[0]));
    int lcs_len = get_lcs_length (-999,0,vec_a);
    cout << "the max size of vec = " << lcs_len << endl;
}

