#include<iostream>
#include<string>
#include<vector>

//FYR : https://www.cs.utexas.edu/users/EWD/transcriptions/EWD03xx/EWD316.9.html#contents

using namespace std;

/* Things to consider
* 1.At max,# of queens in the ROW = 1.
* 2.At max,# of queens in the col = 1
* 3.At max,# of queen in the diagonal = 1. (upward + downward)
*/


void print_solution (int row[],int n,vector< vector<string> > &solution_board) {
   vector<string> rows(n+1);
   string output = "";
    for (int i=0;i<n+1;i++) {
        output = "";
        int row_no = row[i];
        for (int j=0;j<n+1;j++) {
            if (j != row_no ) {
                output += ".";
            } else {
                output += "Q";
            }
        }
        rows[i] = output ;
    }
    solution_board.push_back(rows);
}


void enum_queen(int input,int k,int c,int solution_size
                ,bool col[],bool left_diag[],bool right_diag[],int row[]
                ,vector< vector<string> > &solution_board ) {

      if (k == (solution_size - 1)) {
          //cout << "found the solution" <<endl;
          print_solution (row,k,solution_board);
      } else {
          k = k + 1;
          for (int i=0;i<c;i++) {
              //Think of board 
              if (col[i] && left_diag[k+i] && right_diag[k-i+(input -1)]) {
                  //cout << "( " << i << "," << k+i << "," << k-i+3 << ")" << endl;
                  row[k] = i;
                  //SET
                  col[i] = false;
                  left_diag[k+i]= false;
                  right_diag[k-i+(input -1)] = false;
                  enum_queen (input,k,c,solution_size
                          ,col,left_diag,right_diag,row
                          ,solution_board);
                  //RESET
                  col[i] = true;
                  left_diag[k+i]= true;
                  right_diag[k-i+(input -1)] = true;
              } 
          }
      }
}


int main () {
    int no_of_queen = 5 ;
    bool col[no_of_queen];
    bool left_diag[no_of_queen * 2 -1];
    bool right_diag[no_of_queen * 2 -1];
    int row[no_of_queen];

    for (int i=0;i<no_of_queen;i++) {
        col[i] = true;
    }
    for (int i=0;i< (no_of_queen*2);i++) {
        left_diag [i] = true;
        right_diag[i] = true;
    }
    vector< vector<string> > solution_board;
    enum_queen(no_of_queen,-1,no_of_queen,no_of_queen
            ,col,left_diag,right_diag,row
            ,solution_board) ;

    int len = solution_board.size();

    cout << "the solution size " << len << endl;
    
    for (int i=0;i<len;i++) {
        int in_size = solution_board[i].size();
        for (int j=0;j<in_size ;j++) {
            cout << solution_board[i][j] << endl;
        }
        cout << endl;
    }


}
