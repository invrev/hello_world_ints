#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
    int sz = board.size();
    //check row
    for (int i=0;i<sz;i++) {
        vector<bool> row_test (sz);
        vector<bool> col_test (sz);
        vector<bool> row_col_test (sz);
        fill(row_col_test.begin(),row_col_test.end(),false);
        fill(col_test.begin(),col_test.end(),false);
        fill(row_test.begin(),row_test.end(),false);
        for (int j=0;j<sz;j++) {
            int row_offset = j%3 + 3*(i%3);
            int col_offset = j/3 + 3*(i/3);
            //cout << "( " << i << "," << j << "," << row_offset << "," << col_offset << ")" << endl;
            if (board[i][j] == '.' && board[j][i] == '.' && board[row_offset][col_offset] == '.') {
                continue;
            }
            if (row_test[board[i][j] - '0'] == true 
                    || col_test[board[j][i] - '0'] == true 
                    || row_col_test [board [row_offset][col_offset] - '0'] == true) {
                return false;
            } 

            if (board[i][j] != '.')  {
                row_test[board[i][j] - '0'] = true;
            }

            if (board[j][i] != '.')  {
                col_test[board[j][i] - '0'] = true;
            }
            if (board[row_offset][col_offset] != '.') {
                row_col_test[board[row_offset][col_offset] - '0'] = true;
            }

        }
        //cout << "----------------" << endl;
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

    //[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]

    board[0][0] = '5';
    board[0][2] = '3';
    board[0][4] = '7';

    isValidSudoku(board);
}

