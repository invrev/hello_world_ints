#include<iostream>
#include<vector>
using namespace std;


void solveSudoku(vector<vector<char> > &board) {
    dfs(board, 0);
}

bool dfs(vector<vector<char> > &board, int pos) {
    int n = board.size();
    if (pos == n*n)
    {
        return true;
    }
    int x = pos / n;
    int y = pos % n;
    if (board[x][y] == '.')
    {
        for (char c='1'; c<='9'; ++c)
        {
            board[x][y] = c;
            if (validate(board, x, y) && dfs(board, pos+1))
            {
                return true;
            }
            board[x][y] = '.';
        }
    }
    else
    {
        if (dfs(board, pos+1))
        {
            return true;
        }
    }
    return false;
}

bool validate(vector<vector<char> > &board, int x, int y) {
    char c = board[x][y];
    for (int i=0; i<9; ++i)
    {
        if (y != i && board[x][i] == c)
        {
            return false;
        }
        if (x != i && board[i][y] == c)
        {
            return false;
        }
    }
    int xx = x / 3 * 3;
    int yy = y / 3 * 3;
    for (int i=xx; i<xx+3; ++i)
    {
        for (int j=yy; j<yy+3; ++j)
        {
            if (x != i && y != j && board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}
