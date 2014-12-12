#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//acbcacdef //acdef
//Idea store the index as the value in the array
int longestSubstringWoRepeatingChar(string &a) {
    int indexStore[26];
    int maxLen = 0;
    memset(indexStore,-1,sizeof(int)*26);
    int len = 0;
    //Iterate over the string
    int m = a.length();
    for (int i=0;i<m;i++,len++) {
        if ( indexStore[a[i]-'a'] >= 0 ) { //find duplicate char
            maxLen = max(len,maxLen);
            memset(indexStore,-1,sizeof(int)*26);
            //Reset indexStore and len
            indexStore[a[i]-'a'] = i;
            len = 0;
        }
        indexStore[a[i]-'a'] = i;
    }
    return maxLen;
}

void test(string input) {
    cout << "The longest substring " << input << " len = " << longestSubstringWoRepeatingChar(input) << endl;
}


int main () {
    test("bbbbb");
    test ("abcabcbb");
}

