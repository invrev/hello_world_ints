#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

//note strings are of equal length
int is_isomorphic (string a,string b) {
    int len = a.length();
    for (int i=0;i<len;i++) {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }

    int store_arr [26] ;
    for (int i=0;i<26;i++) {
        store_arr [i] = -1;
    }
    //Determine 1:1 relationship between string a and string b 
    //Use array with index from on string and value as the other string
    for (int i=0;i<len;i++) {
        int index_ = a[i] - 'a';
        int value_ = b[i] - 'a';
        if (store_arr[index_] == -1) {
            store_arr[index_] = value_;
        }
        else if (store_arr[index_] != value_) {
           return 0; 
        }
    }
    return 1;
}

int main () {

    if (is_isomorphic ("abca","zbxz")  == 1) {
        cout << "strings are isomophic " << endl;
    } else {
        cout << "strings are not isomophic " << endl;
    }

    if (is_isomorphic ("abca","opqr") == 1 ) {
        cout << "strings are isomophic " << endl;
    } else {
        
        cout << "strings are not isomophic " << endl;
    }


}
