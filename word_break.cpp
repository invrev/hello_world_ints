#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
     int dict_len = dict.size();
     string st = "";
     for(auto i = dict.begin();i != dict.end(); i++ ) {
         st += *(i);
         cout << "st = "<< st << endl;
     }
     if (s == st) {
         return true;
     }
     return false;
}

int main () {
    unordered_set<string> split_dict ;
    split_dict.insert("a");
    split_dict.insert("b");
    wordBreak ("ab",split_dict);
}

