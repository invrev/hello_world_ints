#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_opt (vector<int>& result) {
    for (int i=0;i<result.size();i++) {
        cout << result[i]  << " ";
    }
    cout << endl;
}

void enum_parenthesis (int n,int left,int right,string& result,vector<string>& sv) {
    if ( left+right == n+n ) {
    //if ( total == 2*n ) {
        cout << result << endl;
        sv.push_back(result);
    } else {
        if (left < n) {
            result.push_back('(');
            enum_parenthesis(n,left+1,right,result,sv);
            //increase size
            //result.resize(result.size() - 1);
            result.pop_back();
        } 
        if (right < left) {
            result.push_back(')');
            enum_parenthesis(n,left,right+1,result,sv);
            //increase size
            //result.resize(result.size() - 1);
            result.pop_back();
        }
    }
}

int main () {
    //generate all valid parenthesis
    string result ;
    vector<string> sv;
    enum_parenthesis (3,0,0,result,sv);

}

