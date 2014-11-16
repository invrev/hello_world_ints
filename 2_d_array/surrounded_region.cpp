#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//As stack can overflow use the BFS 

void printBoard (vector<vector<char> > &board) {
    int len = board.size();
    for (int i=0;i<len;i++) {
        for (int j=0;j<board[i].size();j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

//BFS visit all neighbours
//If 'O' / 'I'
void visit (queue<int>& visit_q,vector<vector<char> > &board,int i,int j) {
    int m = board.size();
    if (m == 0) {
        return ;
    }
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }
    int ele =  i*n + j;
    visit_q.push(ele);
    board[i][j] = 'I';
}

void bfs (vector<vector<char> > &board,int i,int j) {  //,queue<int>& visit_q1
   
    queue<int> visit_q;

    int m = board.size();
    int n = board[0].size();
    visit (visit_q,board,i,j);
    while (!visit_q.empty()) {
        int row_col = visit_q.front();
        visit_q.pop();
        int row = row_col / n;
        int col = row_col % n;
        visit(visit_q,board,(row+1),col);
        visit(visit_q,board,(row-1),col);
        visit(visit_q,board,row,(col-1));
        visit(visit_q,board,row,(col+1));
    }
    
}

void solve(vector<vector<char> > &board) {

    int m = board.size();
    if (m <= 2 ) {
        return ;
    }
    int n = board[0].size();
    if (n <= 2) {
        return ;
    }
   
    queue<int> visit_q;
    //traverse to left and right
    for (int i=0;i<m;i++) {
        if (board[i][0] == 'O') {
            bfs(board,i,0);
        }
        if (board[i][n-1] == 'O') {
            bfs(board,i,n-1);
        }
    }

    //traverse to top and bottom
    for (int i=1;i<n-1;i++) {
        if (board[0][i] == 'O') {
            bfs(board,0,i);
        }
        if (board[m-1][i] == 'O') {
            bfs(board,m-1,i);
        }
    }

    for(int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j] == 'I') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
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
