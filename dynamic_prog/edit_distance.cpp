#include<iostream>
#include<string>
using namespace std;

int is_match  (string a,string b) {
    if (a[0] == b[0]) {
        return 0;
    } return 1;
}

int edit_distance (string word1,string word2) {
    if (word1.length() == word2.length() && word1.length() == 0) {
        return 0;
    } else if (word1.length() == 0) {
        return word2.length ();
    } else if (word2.length() == 0) {
        return word1.length();
    } else {
        int insert_ = edit_distance (word1,word2.substr(1,word2.length() -1 )) + 1 ;
        int delete_ = edit_distance (word1.substr(1,word1.length() -1),word2) + 1;
        int match_ = edit_distance (word1.substr(1,word1.length() - 1),word2.substr(1,word2.length() - 1)) + is_match (word1,word2) ;
        int opt = match_;
        if (opt > delete_) {
           opt = delete_; 
        } 
        if (opt > insert_) {
            opt = insert_;
        }
    }
}

void do_recrsive_print (string st) {
    if (st.length() == 0) {
        return ;
    } else {
        cout << st[0] << endl;
        do_recrsive_print (st.substr(1,st.length()-1));
    }
}

int main () {
    string st = "kitten";
    string st1 = "sitten";
    //do_recrsive_print (st);

    int dist = edit_distance (st,st1);
    cout << "the edit distance = " << dist << endl;
}


