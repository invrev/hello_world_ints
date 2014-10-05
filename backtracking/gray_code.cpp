#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

vector<int> gray_code_vec;

void print_gray_code(vector<int> a,int k) {
    int sum = 0;
    for (int i=0,j=k;i<=k;i++,j--) {
        cout << a[i] << ",";
        int multiplier = pow(2,j);
        sum += (multiplier * a[i]);
    }
    cout << endl;
    gray_code_vec.push_back(sum);
}

void gray_code_enumerate (vector<int>& a ,int k,int solution_size) {
    if (k == (solution_size-1) ) {
       print_gray_code(a,k);
    } else {
        k = k + 1;
        gray_code_enumerate (a,k,solution_size); //(n-1) !
        a[k] = 1 - a[k];                        //Flip a[k]
        gray_code_enumerate (a,k,solution_size); //(n-1)!
    }
}

vector<int> grayCode(int n) {
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        a[i] = 0;
    }
    gray_code_enumerate (a,-1,n);

    for (int i=0;i<gray_code_vec.size();i++) {
        cout << gray_code_vec[i] << ",";
    }
    cout << endl;
}

int main () {
    //grayCode(3);
    grayCode(2);
}
