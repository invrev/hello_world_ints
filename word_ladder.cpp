#include<iostream>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
    
    int len = start.length();
    queue<pair <string,int> > output;
    output.push(pair<string,int> (start,1) );
    int min_len = 0;
    while (!output.empty()) {
        //string tmp = output.front();
        pair<string,int> tmp (output.front());
        string tmp_str = tmp.first;
        output.pop();
        for (int i=0;i<len;i++) {
            char prev = tmp_str [i];
            for (int j=0;j<26;j++) {
                tmp_str [i] = 'a' + j;
                if (tmp_str == end) {
                    return tmp.second + 1;
                    //return min_len;
                }
                if (dict.find(tmp_str) != dict.end() ) {
                    //cout << tmp_str << endl;
                    output.push(pair<string,int> (tmp_str,tmp.second + 1) );
                    dict.erase(tmp_str);
                    min_len++;
                }
            }
            tmp_str[i] = prev;
        }
    }
    return 0;
}

int main () {
    //unordered_set<string> dict ( {"hot","dot","dog","lot","log"} );
    //string start = "hit";
    //string end = "cog";

    unordered_set<string> dict ( {"a","b","c"} );
    string start = "a";
    string end = "c";
    int l = ladderLength (start,end,dict);
    cout << "the min length = " << l << endl;

}
