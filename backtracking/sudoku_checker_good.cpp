#include<iostream>
#include<vector>
using namespace std; 

//using bitmask
bool isValidSudoku(vector<vector<char> >& board) {
    int row_test[9] = {0};
    int col_test[9] = {0};
    int subregion_test[9] = {0};
    int sz = board.size();
    for (int i=0;i<sz;i++) {
        for (int j=0;j<sz;j++) {

            //cout << "( " << i << "," << j << "," << (i/3)*3 + j/3 << ")" << endl;
            if (board[i][j] == '.') {
                continue;
            } else {
                //This cell value should be unique across row,col,sub region
                int cell = board[i][j] - '0';
                int mask = 1 << cell;
                int combine_result = (row_test[i] || col_test[j] 
                                || subregion_test[(i/3)*3 + j/3] );
                if (combine_result && mask ) {
                    return false;
                }
                row_test[i] |= mask;
                col_test[j] |= mask;
                subregion_test[(i/3)*3 + j/3] |= mask;
            }
        }
    }
    return true;
}

int main () {
    vector<vector <char> > board;
    for (int i=0;i<9;i++) {
        vector<char> sub_region (9);
        for (int j=0;j<9;j++) {
            sub_region [j] = '.';
        }
        board.push_back(sub_region);
    }

    board[0][0] = '5';
    board[0][2] = '3';
    board[0][4] = '7';

    isValidSudoku(board);
}



