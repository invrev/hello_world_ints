#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

//2s complement arithmetic is used in c++


int main () {

    int num = INT_MAX;
    cout << "num = " << num << " num OF ="  << num+1 << endl;

    int num1 = num + 1;
    int num2 = num + 2;
    //obvious 
    if (num1 < num2) {
        if (abs(num1) < 0) {
            cout << "overflow occured after abs " << "(" << num1 << "," << num2 << ")" << endl;
        }
        cout << "followed normal route"  << "(" << num1 << "," << num2 << ")" << endl;
    } else {
        cout << "overflow occured" << "(" << num1 << "," << num2 << ")" << endl;
    }


}
