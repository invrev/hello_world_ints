#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numDecodings(string s) {
    
    int n = s.length();
    if (n == 0) {
        return n;
    }
    vector<int> opt (n+1) ;
    //init 
    opt[n] = 1;
    if (s[n-1] >= '1' && s[n-1] <= '9') {
        opt[n-1] = 1;
    } 
    else {
        //invalid chars like blank
        opt[n-1] = 0;
    }
    for (int i=n-2;i>=0;i--) {
        //invalid chars like "00"
        //handle "101" and "00"
        if (s[i] < '1' || s[i] > '9') {
            opt[i] = 0;
            //return 0;
        } else if (s[i] > '2' || (s[i] == '2' && s[i+1] > '6') ) { //To handle case "230"
            //it can be decoded only 1 way
            opt[i] = opt[i+1] ;
        } else {
            //it can be decoded in 2 ways
            opt[i] = opt[i+1] + opt[i+2];
        }
    }
    return opt[0]; 
}



int main () {
    string s = "27";
    int result = numDecodings (s);
    cout << "# of decodings  = " << result << endl;

}
