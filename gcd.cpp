#include<iostream>
#include<stdlib.h>
using namespace std;

//To compute gcd
//Base case
//    gcd (a,0) = a
//    gcd (a,a) = a
//Recursion case
//    gcd(a,b) = gcd (a,a-b) a>b
//    gcd(a,b) = gcd (a-b,b) b>a
//

int compute_gcd (int a,int b) {
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    } else if (a == b) {
        return a;
    }
    if (a < b) {
        //used "abs" for the sake of consistency between 2 calls 
        return (compute_gcd (a,abs(a-b)));
    }else {
        return (compute_gcd (a-b,b));
    }
}

int main () {

    int a = 3;
    int b = 5;
    cout << "a-b = " << abs(a-b) << endl;
    cout << "b-a= " << (b-a) << endl;
    int ans_ = compute_gcd(a,b);
    cout << "gcd for (" << a <<  "," << b << ") = " << ans_ << endl;

}
