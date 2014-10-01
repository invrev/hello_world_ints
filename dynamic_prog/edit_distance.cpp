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

//Iterative version
//Row Major 
int edit_distance1 (string word1,string word2) {
    int m = word1.length();
    int n = word2.length();
    int solution_vector[m+1][n+1];
    //cout << "(" << m << "," << n << ")" << endl;
    //cout << word1 << " , " << word2 << endl;

    //Initialize columns
    for (int j=0;j<=n;j++) {
        solution_vector[0][j] = j;
    }
    for (int i=1;i<=m;i++) {
        //Lazy row initialization
        solution_vector[i][0] = i;
        for (int j=0;j<=n;j++) {
            //min_cost of insert and delete
            int min_cost = min( solution_vector[i-1][j] + 1,solution_vector[i][j-1] + 1);
            //As initialization start at 0th row and column use i-1,j-1 as the current string index for 
            //word1 and word2
            if (word1[i-1] == word2[j-1]) {
                //cout << "match char ("<< i << "," << j << ")" << endl;
                solution_vector[i][j] = min(solution_vector[i-1][j-1],min_cost);
            } else {
                solution_vector[i][j] = min(solution_vector[i-1][j-1] + 1,min_cost);
            }
        }
    }
    return (solution_vector[m][n]);
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
    //string st = "kitten";
    //string st1 = "sitten";

    //string st = "ramayan";
    //string st1 = "mahabhart";
    string st = "algorithm";
    string st1 = "altruistic";
    //do_recrsive_print (st);

    int dist = edit_distance (st,st1);
    cout << "the edit distance = " << dist << endl;
    dist = edit_distance1 (st,st1);
    cout << "the edit distance = " << dist << endl;
}


