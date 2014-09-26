#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Rotate the matrix by  90.

void print_2_d_array(int mat[][4],int len) {
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

//TODO : WHAT @ RECTANGLE MATRIX
void rotate_mat_by_ninty_deg (int mat[][4],int len,int width) {

    print_2_d_array (mat,4);
    //Diagonal swap
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            if (i != j && i > j) {
                do_swap(&mat[i][j],&mat[j][i]);
            }
        }
    }

    print_2_d_array (mat,4);
    cout << " ---------------- " << endl;
    //Vertical swap
    int mid = len / 2;
    int last_col = len - 1;
    for (int i=0;i<len;i++) {
        last_col = len - 1;
        for (int j=0;j<len;j++) {
            if (j < mid ) {
                do_swap(&mat[i][j], &mat[i][last_col]);
            }
            last_col = last_col - 1;
        }
    }

    print_2_d_array (mat,4);
}

int main () {

    int mat_2 [][4] = {
         {1,2,3,0}
         ,{4,0,6,11}
         ,{7,8,0,12}
         ,{13,14,15,16}
    
    };
    
    rotate_mat_by_ninty_deg (mat_2,4,4);
}
