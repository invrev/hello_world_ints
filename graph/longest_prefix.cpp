#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int ht = strs.size();
    if (ht == 0) {
        return "";
    } else {
        //pick the first string
        for (int i=0;i<strs[0].size();i++) {
            char c = strs[0][i];
            //Iterate over all the rows (strs.size not strs[j].size())
            for (int j=1;j<strs.size();j++) {
                if (strs[j].size() == i || strs[j][i] != c) {
                    return strs[0].substr(0,i);
                }
            }
        }
    }
    return(strs[0]);
}

bool isAnagram (string &first,string &second) {
    int m = first.length();
    int n = second.length();
    if (m == n && m == 0 ) return true;
    if (m != n ) return false;
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    int m_start = 0;
    int n_start = 0;
    while (m_start < n) {
        if (first[m_start++] != second[n_start++]) {
            return false;
        }
    }
    return true;
}

void test (string first,string second) {
    if ( true == isAnagram (first,second) ) {
        cout << "(" << first <<"," << second << ")" <<  "are anagrams" << endl;
    } else {
        cout << "(" << first <<"," << second << ")" <<  "are not anagrams" << endl;
    }
}

int main () {
    test ("mary","army");
    test ("maryLand","armyBand");
}
