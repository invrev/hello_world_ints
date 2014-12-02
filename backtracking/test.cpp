#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main () {
    string t = "2345";
    int len = t.length();
    for (int i=0;i<len;i++) {
        int t1 = t[i] - '0';
        cout << t1 << " ";
    }
    cout << endl;

    unordered_map< vector<int> ,int> test_map;
    vector<int> t_vec ;
    t_vec.push_back(2);
    test_map[t_vec] = 2;

}
