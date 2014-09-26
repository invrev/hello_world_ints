#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Determine string contain all the unique charcters or not no addition ds
//O(n^2) w/o any additional DS
void check_uniqueness (string input_str) {
    int len = input_str.length();
    int is_unique = 1;
    for (int i=0;i<len;i++) {
        if (is_unique == 0) {
            break; 
        }
        for (int j=i+1;j<len;j++)  {
            if (input_str[i] == input_str[j]) {
               cout << "the string  " << input_str << " did not contain unique characters." << endl;
               is_unique = 0;
               break;
            }
        }
    }

    if (is_unique == 1) {
        cout << "the string  " << input_str << " contain unique characters." << endl ;
    }
}


int main () {
    check_uniqueness ("HAH");
    check_uniqueness ("ABCDEFR");
}
