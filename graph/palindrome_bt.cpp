#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool isPalindrome(string& input,int start,int end) {
    while (start < end) {
        if (input[end--] != input[start++]) {
            return false;
        }
    }
    return true;
}

void enum_palindrome(string input,int k,vector<string>& sv,vector<vector<string> >& outer_sv) {
    if (k == input.length())  {
        outer_sv.push_back(sv); 
        return;
    }else {        

        //Iterate with the two candidates where k = start and i = end
        for (int i = k;i<input.length();i++) {
            //Check the palindrome sub strings os various length
            if (isPalindrome(input,k,i) == true ) {
                sv.push_back(input.substr(k,i-k+1));
                //Increase the level or increase the end at each level
                enum_palindrome(input,i+1,sv,outer_sv);
                sv.pop_back(); //backtrack
            }
        }
    }
}

int main () {

    vector<string> sv;
    vector<vector<string> > outer_sv;
    string input = "aab";
    int k = 0;
    enum_palindrome (input,k,sv,outer_sv);
    
    for (int i=0;i<outer_sv.size();i++) {
        for (int j=0;j<outer_sv[i].size();j++) {
            cout << outer_sv[i][j] << ",";
        }
        cout << endl;
    }
}
