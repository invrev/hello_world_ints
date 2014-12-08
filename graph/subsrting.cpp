#include<iostream>
#include<string>
using namespace std;


//struct UfNode {
//    int val;
//    int size;
//    vector<UfNode*> nextNodes;
//    UfNode(int xval,int xsize) : 
//        val (xval),size(xsize)
//    {
//
//    };
//        
//};
//
//struct UndirectedGraphNode {
//     int label;
//     vector<UndirectedGraphNode *> neighbors;
//     UndirectedGraphNode(int x) : label(x) {};
//};

void gen_substring_ugly(string s) {
    if (s.length() == 0 ) {
        return;
    }
    int start = 0;
    int len = 1;
    int no_of_str = s.length();
    for (int i=0;i<s.length();i++) {
        for (int j=0;j < s.length() && j < no_of_str ;j++) {
            cout << s.substr(j,len) << endl;
        }
        no_of_str -= 1;
        len += 1;
    }
}

void gen_substring(string s) {
    int n = s.length() ;
    int no_of_strings = n - 1;

    //string s = "abcd"
    //pass 0: (all the strings are of length 1)
    //a, b, c, d = 4 strings
    //pass 1: (all the strings are of length 2)
    //ab, bc, cd = 3 strings
    //pass 2: (all the strings are of length 3)
    //abc, bcd = 2 strings
    //pass 3: (all the strings are of length 4)
    //abcd = 1 strings

    //O(n^2)
    for(int pass = 0;pass<n; pass++) {
        int start = 0;
        int end = start + pass;
        for(int j= no_of_strings;j>=0;j--)
        {
            cout << s.substr(start,(end-start+1) ) << endl;
            start++;
            end = start+pass;
        }
        no_of_strings--;
    }
}



int main () {

    string s = "abcd";
    gen_substring (s);

}
