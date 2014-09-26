#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int romanToInt(string s) {

    unordered_map <string,int> u_map = { {"I",1} ,{"V",5} ,{"X",10} 
        ,{"L",50},{"C",100},{"D",500},{"M",1000}
        ,{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}  };
    int len = s.length();
    int sum = 0;
    for (int i=0;i<len;i++) {
        bool is_match = false;
        if (len >= (i+2) )  {
            string res1 = s.substr(i,2);
            auto search = u_map.find(res1);
            if (search != u_map.end()) {
                sum += search->second;
                cout << "res1 = " << res1 << endl;
                i = i + 1;
                continue;
            } 
        } 
        string res = s.substr(i,1);
        cout << "res = " << res << endl;
        auto search = u_map.find(res);
        if (search != u_map.end()) {
            sum += search->second;
        } 
    }
    return sum;
}

int main () {
    string st = "MCDLXXVI";
    
    int ans = romanToInt (st);
    cout << "The ans is " << ans << endl;
}

