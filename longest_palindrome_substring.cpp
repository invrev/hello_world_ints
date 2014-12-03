#include<iostream>
#include<string>
#include<vector>
using namespace std;


string pre_process (string input) {
    int len = input.length();
    string suffix = "^$";
    if (len == 0) {
       return  suffix ;
    } 

    string ret = "^";
    for (int i=0;i<len;i++) {
        ret += "#" + input.substr(i,1);
    }
    ret += "#$";
    return ret;
}

string longestPalindrome (string ip) {
    string s = pre_process(ip);
    int n = s.length();
     
    vector<int> p(n,0);
    int mid = 0;
    int max = 0;

    //escaping the first and last char
    for (int i=1;i<n-1;i++) {
        int mirror = 2*mid - 1; // (mid - (i-mid) )
        if (max > i) {
            p[i] = min(p[mirror],max - i);
        } else {
            p[i] = 1;
        }
        while (s[i +  p[i]] == s[i - p[i] ] ) {
            p[i]++;
        }

        //Adjust mid and max based on the current match/p[i]
        if (i + p[i] > max) {
            max = i + p[i]; 
            mid = i;
        }
    }

    int max_len = 0;
    int mid_index = 0;
    
    for (int i=1;i<n-1;i++) {
        if (p[i] > max_len) {
            max_len = p[i];
            mid_index = i;
        }
    }

    //cout << "( " << mid_index  << "," <<  max_len << " )" << endl;
    return ip.substr( (mid_index - max_len)/2,max_len-1);

}


int main () {

    //string s = "caba";
    //string s = "abacdfgdcaba";
    string s = "racecar";
    string op_ = longestPalindrome (s);
    cout << " ( " << s << " , " << op_ << " )" << endl;

}

