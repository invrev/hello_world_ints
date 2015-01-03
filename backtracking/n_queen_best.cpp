#include<iostream>
using namespace std;

//https://www.cs.utexas.edu/users/EWD/transcriptions/EWD03xx/EWD316.9.html#contents

/* Things to consider
* 1.At max,# of queens in the ROW = 1.
* 2.At max,# of queens in the col = 1
* 3.At max,# of queen in the diagonal = 1. (upward + downward)
*/

void print_solution (int row[],int n) {
    for (int i=0;i<n+1;i++) {
        cout << row[i] << " " ;
    }
    cout << endl;
}


void enum_queen(int input,int k,int c,int solution_size
                ,bool col[],bool left_diag[],bool right_diag[],int row[],int& solution_count) {

      if (k == (solution_size - 1)) {
          //cout << "found the solution" <<endl;
          print_solution (row,k);
          solution_count++;
      } else {
          k = k + 1; //iterate over row
          for (int i=0;i<c;i++) { //iterate over columns
              //Think of board 
              //left diag = row+col , right digonal = row-col + (no_of_queen - 1)
              if (col[i] && left_diag[k+i] && right_diag[k-i+(input -1)]) {
                  //cout << "( " << i << "," << k+i << "," << k-i+3 << ")" << endl;
                  row[k] = i;
                  //SET
                  col[i] = false;
                  left_diag[k+i]= false;
                  right_diag[k-i+(input -1)] = false;
                  enum_queen (input,k,c,solution_size,col,left_diag,right_diag,row,solution_count);
                  //RESET /backtrack
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
    bool left_diag[no_of_queen * 2 -1]; //# of left digonals 
    bool right_diag[no_of_queen * 2 -1]; //# of right digonals
    int row[no_of_queen];

    for (int i=0;i<no_of_queen;i++) {
        col[i] = true;
    }
    for (int i=0;i< (no_of_queen*2);i++) {
        left_diag [i] = true;
        right_diag[i] = true;
    }
    int solution_cnt = 0;

    enum_queen(no_of_queen,-1,no_of_queen,no_of_queen
            ,col,left_diag,right_diag,row,solution_cnt ) ;

    cout << "solution_cnt = " << solution_cnt << endl;
}
