#include<iostream>
using namespace std;
//compute the parity of 64-bit non negative number
//If #of 1's in the number is odd then parity = 1 (odd #)  else parity = 0 (even #)
//1.compute the # of ones in an given non negative number



void compute_no_of_ones(int test_no,int *cnt) {
    while (test_no != 0 ) {
        test_no = test_no & (test_no - 1) ;
        *cnt += 1;
    }
}

void what_is_parity(int no) {
    int no_of_ones = 0; 
    compute_no_of_ones (no,&no_of_ones);
    if (no_of_ones % 2 == 0) {
        cout << no << " having 0 parity." << endl;
    } else {
        cout << no << " having 1 parity." << endl;
    }
}


int main () {
    what_is_parity(6);
    what_is_parity(66);
    what_is_parity(7);
    what_is_parity(23);
    what_is_parity(24);
}
