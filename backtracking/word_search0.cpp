#include<iostream>
#include<string>
#include<vector>
using namespace std;

//This problem reminds flood fill algorithm

//bound check
bool is_in_board(vector<vector<char> > &board,int i, int j) {
    if(i < 0 || i >= board.size()) {
        return false;
    }
    if(j < 0 || j >= board[i].size()) {
        return false;
    }
    return true;
}
    
bool traverse_helper (vector<vector<char> > &board,int i,int j,int row_size
                     ,int k,string& word,bool** mem) {
    //k : reach always increment by 1
    if ( k == word.length() )  {
        return true ;
    }
    //The problem : movement is asymetric so bound check will create problem
    //if (i < row_size && j < board[i].size() ) { 
    if(is_in_board(board,i, j)) {
        if (mem[i][j] == false &&  board[i][j] == word[k]) {
            //move left
            mem[i][j] = true;
            if ( traverse_helper(board,i+1,j,row_size,k+1,word,mem) ) {
                return true;
            }
            //move down
            else if (traverse_helper(board,i-1,j,row_size,k+1,word,mem) ) {
                return true;
            }
            //move down
            else if (traverse_helper(board,i,j+1,row_size,k+1,word,mem) ) {
                return true;
            }
            //move up 
            else if (traverse_helper(board,i,j-1,row_size,k+1,word,mem) )  {
                return true;
            }
            //Reset the function
            mem[i][j] = false;
            return (false);
        }
    }
    return (false);   
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
    //bool vector intialization created problems as it is not simple as 2-d int vector initialization
    bool **mem;
    mem = new bool*[m];
    for (int i=0;i<m;i++) {
        mem[i] = new bool[ board[i].size() ];
        for (int j=0;j<board[i].size();j++) {
            mem[i][j] = false;
        }
    }
            
    //Find start match
    for (int i=0;i<m;i++) {
        for (int j=0;j<board[i].size();j++) {
            //if (board[i][j] == word[0]) {
                if ( traverse_helper(board,i,j
                        ,m,0,word,mem) ) return true;
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
