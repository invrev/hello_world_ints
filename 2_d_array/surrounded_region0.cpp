#include<iostream>
#include<vector>
using namespace std;


void printBoard (vector<vector<char> > &board) {
    int len = board.size();
    for (int i=0;i<len;i++) {
        for (int j=0;j<board[i].size();j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

bool isSurrounded (vector<vector<char> > &board,int i,int j) {
    
    //cout << "("<< i << "," << j << ")" << endl;
    if (j == board[i].size() - 1 || j == 0 || i == 0 || i == board.size() - 1) {
        return false;
    }
    return true;

}

void dfs (vector<vector<char> > &board,int i,int j) {

    //base condition / exit condition 
    if (i < 0 || j < 0 || j >= board[0].size() || i >= board.size() || board[i][j]  != 'O')  {
        return;
    }
    //if found 'O' move in all directions
    //If board[i][j]  == 'O' then change it to 'I'  
    //Try to see wheather 'I' reached to other 'I'
    board[i][j] = 'I';

    if (i-1 >= 0 && board[i-1][j]  == 'O') {
        dfs(board,i-1,j);
    }
    if (i+1 < board.size() && board[i+1][j]  == 'O') {
        dfs(board,i+1,j);
    }
    if (j-1 >= 0 && board[i][j-1]  == 'O') {
        dfs(board,i,j-1);
    }
    if (j+1 < board[0].size() && board[i][j+1]  == 'O') {
        dfs(board,i,j+1);
    }
}

void solve(vector<vector<char> > &board) {
    
    int m = board.size();
    if ( m <= 2)  return;
    int n = board[0].size();
    if (n <= 2) return;

    //left side
    for (int i=0;i<m;i++) {
        if (board[i][0] == 'O') {
            dfs(board,i,0);
        }
    }

    //right side
    for (int i=0;i<m;i++) {
        if (board[i][n-1] == 'O') {
            dfs(board,i,n-1);
        }
    }

    //top
    for (int i=1;i<n-1;i++) {
        if (board[0][i] == 'O') {
            dfs(board,0,i);
        }
    }

    //bottom
    for (int i=1;i<n-1;i++) {
        if (board[m-1][i] == 'O') {
            dfs(board,m-1,i);
        }
    }
    
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j] == 'I') {
                board[i][j] = 'O';
            } 
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } 
        }
    }

}

int main () {

    char a[] = {'X','X','X','X'};
    char b[] = {'X','O','O','X'};
    char c[] = {'X','X','X','X'};
    char d[] = {'X','X','O','X'};
    vector<char> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<char> bv (b,b+sizeof(b)/sizeof(b[0]));
    vector<char> cv (c,c+sizeof(c)/sizeof(c[0]));
    vector<char> dv (d,d+sizeof(d)/sizeof(d[0]));
    vector<vector <char> > board;
    board.push_back(av);
    board.push_back(bv);
    board.push_back(cv);
    board.push_back(dv);

    printBoard (board);
    solve(board);
    cout << "------------" << endl;
    printBoard (board);

}
