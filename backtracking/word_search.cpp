#include<iostream>
#include<string>
#include<vector>
using namespace std;



bool is_in_board(vector<vector<char> > &board,int i, int j) {
    if(i < 0 || i >= board.size() ) { 
        return false;
    }
    //if(i >= board.size())return false;
    if(j < 0 || j >= board[i].size()) { 
        return false;
    }
    //if(j >= board[i].size())return false;
    return true;
}

bool traverse_helper (vector<vector<char> > &board,int i,int j,int row_size
                     ,int k,string& word,vector<vector <int> >& mem) {
     
    if ( k == word.length() )  {
        return true ;
    }
    bool ret = false;
    //if (i < row_size && j < board[i].size() ) {
    if  ( is_in_board (board,i,j) ) {
        if (mem[i][j] == 0 &&  board[i][j] == word[k]) {
            //move left
            mem[i][j] = 1;
            if ( traverse_helper(board,i+1,j,row_size,k+1,word,mem) ) {
                ret = true;
            }
            //move down
            else if (traverse_helper(board,i-1,j,row_size,k+1,word,mem) ) {
                ret = true;
            }
            //move down
            else if (traverse_helper(board,i,j+1,row_size,k+1,word,mem) ) {
                ret = true;
            }
            //move up 
            else if (traverse_helper(board,i,j-1,row_size,k+1,word,mem) )  {
                ret = true;
            }
            mem[i][j] == 0;
            return (ret);
        }
    }

    //Reset the function
    //mem[i][j] == ret;
    return (ret);
}

bool exist(vector<vector<char> > &board, string word) {

    int len = word.length();
    int m = board.size();
    if (m == len && m == 0) {
        return true;
    }
    if (m == 0) {
        return false;
    }
    //int n = board[0].size();
    //bool **mem;
    //mem = new bool*[m];
    vector<vector <int> > mem_;
    //mem.resize(m);
    //vector<vector<bool> > mem;
    for (int i=0;i<m;i++) {
        //mem[i] = new bool[ board[i].size() ];
        cout << "B4 resize " << endl;
        //mem[i].resize(board[i].size());
        vector <int> tmp_vector;
        for (int j=0;j<board[i].size();j++) {
            //mem[i][j] = false;
            cout << " j = " << j << endl;
            tmp_vector.push_back(0);
        }
        cout << "B4 push_back" << endl;
        mem_.push_back(tmp_vector);
    }
    //Find start match
    for (int i=0;i<m;i++) {
        for (int j=0;j<board[i].size();j++) {
            //if (board[i][j] == word[0]) {
                return traverse_helper(board,i,j
                ,m,0,word,mem_);
                //return false;
            //}
        }
    }
    return false;
}

int main () {
    char a[] = {'a','a'};
    vector<char> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<vector<char> > input;
    input.push_back(av);
    string word = "aaa";
    cout <<  "ans = " << exist (input,word) << endl;

}
