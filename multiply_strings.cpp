#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Store the result in reverse order and while conveting into string change the order
string multiply(string num1,string num2) {
    int m = num1.length();
    int n = num2.length();
   
   //init vector 
   // even 99 * 99 is < 10000, so maximaly 4 digits
    vector<int>result (m+n,0);
    for (int i=0;i<m;i++) {
        int carry = 0;
        int a = num1[m-1-i] - '0';
        for (int j=0;j<n;j++) {
            int b = num2[n-1-j] - '0';
            result[i+j] += carry + a*b;
            carry = result[i+j]/10;
            result[i+j] %= 10;
        }
        result[i+n] += carry;
    }

    int i = result.size() - 1;
    while (i > 0 && result[i] == 0 ) {
        //trim starting zeros
        i--;
    }

    string result_str = "";

    while (i>=0) {
        result_str += (result[i--] + '0');
    }
    
    return result_str;
}


int main () {
    string a = "120";
    string b = "12";
    string result = multiply (a,b);
    cout << "the result = " << result << endl;
}
