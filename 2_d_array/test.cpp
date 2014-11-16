#include<iostream>    
#include<vector>
#include<queue>
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

void fill(vector<vector<char> >& board, int i, int j,queue<int>& visit_q) {
    int row = board.size();
    int col = board[0].size();
    if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O')
        return;
    //cout << " [ " << i << "," << j << " ]>>>>> " << endl;
    int ele = i * col + j;
    visit_q.push(ele);
    //cout << "after pushed element " << endl;
    board[i][j] = 'P';
}


void bfs(vector<vector<char> >& board, int i, int j) {
    int col = board[0].size();
    queue<int> visit_q;
    fill(board, i, j,visit_q);
    //cout << " ( " << i << "," << j << ")" << endl;
    while (!visit_q.empty()) {
        int cur = visit_q.front();
        visit_q.pop();
        //cout << " ( " << cur << ")" << endl;
        int x = cur / col;
        int y = cur % col;
        //cout << " [ " << x << "," << y << "]" << endl;
        fill(board, x-1, y,visit_q);
        fill(board, x+1, y,visit_q);
        fill(board, x,y-1,visit_q);
        fill(board, x,y+1,visit_q);
    }
}

void solve(vector<vector<char> >& board) {
    
    if (board.size() == 0) {
        return;
    }
    if (board[0].size() == 0) {
        return;
    }
    int row = board.size();
    int col = board[0].size();
    queue<int> visit_q;

    // up row
    for (int j = 0; j < col; j++) {
        if (board[0][j] == 'O') {
            bfs(board, 0, j);
        }
    }

    // bottom row
    for (int j = 0; j < col; j++) {
        if (board[row - 1][j] == 'O') {
            bfs(board, row - 1, j);
        }
    }

    // left column
    for (int i = 0; i < row; i++) {
        if (board[i][0] == 'O') {
            bfs(board, i, 0);
        }
    }

    // right column
    for (int i = 0; i < row; i++) {
        if (board[i][col - 1] == 'O') {
            bfs(board, i, col - 1);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if (board[i][j] == 'P') {
                board[i][j] = 'O';
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


