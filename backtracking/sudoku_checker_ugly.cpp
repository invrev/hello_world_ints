#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    int sz = board.size();
    //check row
    for (int i=0;i<sz;i++) {
        vector<bool> row_test (sz);
        fill(row_test.begin(),row_test.end(),false);
        for (int j=0;j<sz;j++) {
            if (board[i][j] != '.' && row_test[board[i][j] - '0'] == true ) {
                return false;
            } else if (board[i][j] != '.' && row_test[board[i][j] - '0' ] == false) {
                row_test[board[i][j] - '0'] = true;
            }
        }
    }
    //check column
    for (int i=0;i<sz;i++) {
        vector<bool> col_test (sz);
        fill(col_test.begin(),col_test.end(),false);
        for (int j=0;j<sz;j++) {
            if (board[j][i] != '.' && col_test[board[j][i] - '0']  == true ) {
                return false;
            } else if (board[j][i] != '.' && col_test[board[j][i] - '0'] == false) {
                col_test[board[j][i] - '0'] = true;
            }
        }
    }
    int sub_sz = sqrt(sz);
    //check sub regions
    for (int k=0;k<sz;k++) {
        vector<bool> row_col_test (sz);
        fill(row_col_test.begin(),row_col_test.end(),false);
        for (int i=0;i<sub_sz;i++) {
            int row_offset = (k/sub_sz) * sub_sz;
 
            for (int j=0;j<sub_sz;j++) {
                int col_offset = (k%sub_sz) * sub_sz;
                if (board[i+row_offset][j+col_offset] != '.' && row_col_test[board[i+row_offset][j+col_offset] - '0'] == true ) {
                    return false;
                } else if (board[i+row_offset][j+col_offset] != '.' && row_col_test[board[i+row_offset][j+col_offset] - '0'] == false) {
                    row_col_test[board[i+row_offset][j+col_offset] - '0'] = true;
                }
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
            sub_region [j] = ' ';
        }
        board.push_back(sub_region);
    }

    board[0][0] = '5';
    board[0][2] = '3';
    board[0][4] = '7';

    isValidSudoku(board);
}

