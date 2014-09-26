#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Determine wheather 2 string are anagram
void is_anagram (string first,string second) {
    string temp1 = first;
    string temp2 = second;
    int f_len = first.length();
    int s_len = second.length();
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    
    if (first == second) {
        cout << "the strings " << temp1 << " and " << temp2 << " are anagrams of each other" << endl;
    } else {
        cout << "the strings " << temp1 << " and " << temp2 << " are not anagrams of each other" << endl;
    }

}


int main () {

    is_anagram ("ABA","ABA");
    is_anagram ("ALGORITHM","LOGARITHM");
    is_anagram ("GORITHM","GARITHM");
}
