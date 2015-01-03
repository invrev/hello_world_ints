#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;


void addSpace (string& input,int k,string &result,int &l) {
    if (k == l-1) {
        string ans = "";
        //cout << result << endl;
        for (int i=0;i<result.length();i++) {
            if (result[i] != '*') {
                ans += result[i];
            }
        }
        cout << ans << endl;

    } else {
        k++;
        //for (int i=k;i<input.length();) {
            addSpace (input,k,result,l);
            if (result[k] == ' ') {
                result[k] = '*';
                addSpace (input,k,result,l);
            } 
            if (result[k] == '*') { //backtrack
                result[k] = ' ';
            } 
        //}
        //
    }
}



void addSpace0 (string& input,int k,string &result,int &l) {
    if (k == l) {
        string ans = "";
        //cout << result << endl;
        for (int i=0;i<result.length();i++) {
            if (result[i] != '*') {
                ans += result[i];
            }
        }
        cout << ans << endl;

    } else {
        //k++;
        for (int i=k+1;i<input.length();i++) {
            //addSpace (input,i,result,l);
            if (result[i] == ' ') {
                result[i] = '*';
                addSpace (input,i,result,l);
            } 
            if (result[i] == '*') { //backtrack
                result[i] = ' ';
            } 
        }
    }
}


void testSpace() {

    string input = "A B C D";
    string result = "A B C D";
    int l = input.length();
    int k = -1;
    //addSpace (input,k,result,l);
    addSpace0 (input,k,result,l);
}

int main () {

    testSpace();
}
