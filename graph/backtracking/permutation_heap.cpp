#include<iostream>
#include<string>
using namespace std;

//In heap method

//Heap method for permutation
void enum_permutation (string& input,int k) {
    if (k == 1) {
        cout << input << endl;
        return;
    } 
    for (int c = 1;c <= k;c++) {
        enum_permutation(input,k-1);
        int j;
        if (k % 2 == 0) {
            j = 1;
        } else {
            j = c;
        }
        swap (input[j],input[k]);
    }
}


int main () {
    string input = "XABCD";
    int k = input.length() - 1;
    enum_permutation(input,k);
}
