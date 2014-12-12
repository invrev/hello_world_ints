#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//given pattern and text match the pattern in the text
bool match(string& text,string& pattern) {
    int m = text.length();
    int n = pattern.length();
    int m_start = 0;
    int n_start = 0;
    int w = 0; //window that increments everytime by 1 after unsuccessful match
    while (w < (m-n+1) && (n_start < n)  ) {
        if (text[m_start++] != pattern[n_start++] ) {
            n_start = 0;
            //Increment w and assign to m_start
            m_start = ++w;
        } 
    }
    if (n_start == n) {
        cout << "the w = " << w << endl;
        return true;
    } 
    return false;
}

//Idea : get the hash of the pattern and match the pattern with text in constant time
//Also computing the hash is constant time if you think implenting the same then the thing is add extra char 
//to hash value and substract the first
bool RabinKarpMatch (string &text,string &pattern) {
    //compute the pattern hash
    unordered_map<string,bool> p_hash;
    p_hash[pattern] = true;
    int m = text.length();
    int n = pattern.length();
    //comapre between the hashes
    for (int i=0;i<m-n+1;i++) {
        string tmp = text.substr(i,n);
        cout << tmp << endl;
        if ( p_hash.find(text.substr(i,i+n)) != p_hash.end() ) {
            cout << "substr found" << endl;
            return true;
        }
    }
    return false;
}


//Computing the hash for the RabinKarp
//Idea is instead of shifting the values in the array store the values in reverse order
int computePreHash(string &text,string &pattern) {
    int m = text.length();
    int n = pattern.length();
    int hash_array[n] ;
    //Intialize the array
    for (int i=0,j=n-1;i<n;i++) {
        hash_array[j--] = text[i] - 'A';
    }

    //Update the array while traversing the text
    for (int i=n;i<m;i++) {
        int next_value = (n-i) % n;
        hash_array[next_value] = text[i] - 'A';
    }
}

int computeHash (int A[],int n) {
    int hash = 0;
    for (int i=0;i<n;i++) {
        hash += A[i];
    }

    hash %= 97;
    return hash;

}


void test (string text,string pattern) {
    //if ( true == match(text,pattern) ) {
    if ( true == RabinKarpMatch(text,pattern) ) {
        cout << " ( " << pattern <<", " << text << ") "  << "is substring" << endl;
    } else {
        cout << " ( " << pattern <<", " << text << ") "  << "is not substring" << endl;
    }
}

int main () {
    test("abcabaa","abaa");
}

