#include<iostream>
using namespace std;

void print_board (char input[][8],int b_len) {
    for (int i=0;i<b_len;i++) {
        for (int j=0;j<b_len;j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int is_diagonal_threat (char input[][8],int row,int col,int b_len) {
    
    int temp_row = row;
    int temp_col = col;
    while ((temp_row < b_len) && (temp_col < b_len)) {
        if (input[temp_row][temp_col] == 'A') {
            return 1; 
        }
        temp_row += 1;
        temp_col += 1;
    }
    temp_row = row;
    temp_col = col;
    while ((temp_row >= 0) && (temp_col >= 0)) {
        if (input[temp_row][temp_col] == 'A') {
            return 1; 
        }
        temp_row -= 1;
        temp_col -= 1;
    }
    temp_row = row;
    temp_col = col;
    while ((temp_row < b_len) && (temp_col >= 0)) {
        if (input[temp_row][temp_col] == 'A') {
            return 1; 
        }
        temp_row += 1;
        temp_col -= 1;
    }
    temp_row = row;
    temp_col = col;
    while ((temp_row >= 0) && (temp_col < b_len)) {
        if (input[temp_row][temp_col] == 'A') {
            //cout << "find diagonal threat." << " temp_row = " << temp_row << " temp_col = " << temp_col << endl;
            return 1; 
        }
        temp_row -= 1;
        temp_col += 1;
    }
    return 0;
}

int is_vertical_threat (char input[][8],int b_len,int col) {
    for (int i=0;i<b_len;i++) {
        if (input[i][col] == 'A') {
            //cout << "find vertical threat." << " row = " << i << " col = " << col << endl;
            return 1; 
        }
    }
    return 0;
}


int is_horizontal_threat (char input[][8],int b_len,int row) {
    for (int i=0;i<b_len;i++) {
        if (input[row][i] == 'A') {
            //cout << "find horizontal threat." << " row = " << row << " col = " << i << endl;
            return 1; 
        }
    }
    return 0;
}

void put_the_queen (char input[][8],int k,int col,int b_len,bool &is_continue) {
    //cout <<  "row = " << k << " col = "  << col <<  endl;
    is_continue = true;
    int start_col = 0;
    while (start_col != b_len) {
        input [k][start_col] = 'X';
        start_col += 1;
    } 
    if ( is_diagonal_threat(input,k,col,b_len) == 0 
        && is_vertical_threat(input,b_len,col) == 0
       && is_horizontal_threat(input,b_len,k) == 0 ) {
        input [k][col] = 'A';
    } 
    else {
        is_continue = false;
    }
    
}

static bool found = false;
void recur_queen_pos (char input[][8],int k,int c,int solution_size) {
    bool is_continue = true;
      if (k == (solution_size - 1)) {
          print_board (input,8);
          cout << "the value k = " << k << endl;
          found = true;
      } else {
        k = k + 1; //row
        for (int i=0;i<c;i++) {
            put_the_queen (input,k,i,c,is_continue); //positions
            //Prune the result
            if (is_continue) {
                recur_queen_pos (input,k,c,solution_size);
            }
            if (found == true) {
                cout << "breaking to avoid seg fault" << endl;
                break;
            }
        }
      }
}


int main () {
    //char board [][4] = {
    //    'X','X','X','X'
    //    ,'X','X','X','X'
    //    ,'X','X','X','X'
    //    ,'X','X','X','X'
    //};
    //recur_queen_pos (board,-1,4,4) ;

    //char board [][2] = {
    //    'X','X'
    //    ,'X','X'
    //};

    ////input,start_row,# cols,total # of rows in the solution
    //recur_queen_pos (board,-1,2,2) ;

    //char board [][3] = {
    //    'X','X','X'
    //    ,'X','X','X'
    //    ,'X','X','X'
    //};
    ////input,start_row,# cols,total # of rows in the solution
    //recur_queen_pos (board,-1,3,3) ;


    char board [][8] = {
        'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
        ,'X','X','X','X'
    };
    recur_queen_pos (board,-1,8,8) ;

}
