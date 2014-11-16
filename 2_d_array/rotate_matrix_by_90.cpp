#include<iostream>
#include<string>
#include<vector>
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

int do_swap (int& a,int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}


//Basically, divide the array into 4 along the diagonals, then for each element in the top quadrant
//, place it into the slot 90 degrees cw, and the old 90 in 180 degrees cw
//, and the old 180 in 270 degrees , and the old 270 in the original place.

/****************************************
 * The rules of the index:
 * (i, j) ---> (j, n-i-1)
 * (j, n-i-1) ---> (n-i-1, n-j-1)
 * (n-i-1, n-j-1) ---> (n-j-1, i)
 * (n-j-1, i) ---> (i, j)
 * We can do it from end to begin,
 * this way can solve it in place.
 * *************************************/

void rotate(vector<vector<int> > &matrix) {
    int i, j, n;
    n = matrix.size();
    for (i = 0; i <= n/2; i++) {
        for (j = i; j < n-i-1; j++) {
            swap(matrix[i][j], matrix[n-j-1][i]);
            swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
            swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
        }
    }
}


// N-j, i --> i, j --> N-j, i --> N-i, N-j --> j, N-i --> N-i, j
public void rotate(int[][] matrix) {
 int n = matrix[0].length; 
 for (int i = 0; i < Math.floor(n/2) ; i++) {
  for (int j = i; j < n-1-i; j++) {
    int temp = matrix[i][j]; 
    matrix[i][j] = matrix[n-1-j][i]; 
    matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; 
    matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; 
    matrix[j][n-1-i] = temp; 
  }
 }
}

//TODO : WHAT @ RECTANGLE MATRIX
void rotate_mat_by_ninty_deg (int mat[][4],int len,int width) {

    print_2_d_array (mat,4);

    cout << "--------------" << endl;
    //Diagonal swap
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            if (i != j && i > j) {
                do_swap(mat[i][j],mat[j][i]);
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
                do_swap(mat[i][j], mat[i][last_col]);
            }
            last_col = last_col - 1;
        }
    }

    print_2_d_array (mat,4);
}

int main () {

    //int mat_2 [][4] = {
    //     {1,2,3,0}
    //     ,{4,0,6,11}
    //     ,{7,8,0,12}
    //     ,{13,14,15,16}
    //
    //};


    int mat_2 [][4] = {
         {1,2,3,4}
         ,{5,6,7,8}
         ,{9,10,11,12}
         ,{13,14,15,16}
    
    };
    
    rotate_mat_by_ninty_deg (mat_2,4,4);
}

