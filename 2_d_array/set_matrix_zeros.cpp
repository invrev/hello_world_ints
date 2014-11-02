#include<iostream>
#include<vector>
using namespace std;


//Idea : 
//1.Always first row / column is at the start/end when we set the elements zero
//So use those places to to save the location of zeros
//And save the status of first row/column in the 2 boolean variables.

void print_vec  (vector<vector<int> > &matrix) {
    cout << "MAT OSZ === " <<  matrix.size() << endl;
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[i].size();j++) {
            //cout << "MAT ISZ === " <<  matrix[i].size() << endl;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}


void setZeroes(vector<vector<int> > &matrix) {

    print_vec (matrix);

    //O(2n) scan
    int row_len = 0;
    int col_len = 0;
    bool is_row_zero = false;
    bool is_col_zero = false;
    row_len = matrix.size();
    if (row_len > 0) {
        col_len = matrix[0].size();
    }
    
    for (int j=0;j<col_len;j++) {
        if (matrix[0][j] == 0) {
            is_row_zero = true;
            break;
        }
    }
    for (int i=0;i<row_len;i++) {
        if (matrix[i][0] == 0) {
            is_col_zero = true;
            break;
        }
    }

    //Now start O(n^2) scan
    for (int i=1;i<row_len;i++) {
        for (int j=1;j<col_len;j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; //store 0 in the row
                matrix[0][j] = 0; //store 0 in the col
            }
        }
    }

    //EXcept first col
    for (int j=1;j<col_len;j++) {
        if (matrix[0][j] == 0) {
            for (int i=0;i<row_len;i++) {
                matrix[i][j] = 0;
            }
        }
    }
    //Except first row
    for (int i=1;i<row_len;i++) {
        if (matrix[i][0] == 0) {
            for (int j=0;j<col_len;j++) {
               matrix[i][j]  = 0;
            }
        }
    }

//Combining above 2
 //// set zeroes except the first row and column
 //   for (int i = 1; i < matrix.length; ++i) {
 //       for (int j = 1; j < matrix[0].length; ++j) {
 //           if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
 //       }
 //   }





    if (is_row_zero) {
        for (int j=0;j<col_len;j++) {
            matrix[0][j] = 0;
        }
    }

    if (is_col_zero) {
        for (int i=0;i<row_len;i++) {
            matrix[i][0] = 0;
        }
    }

    print_vec (matrix);
    
}

int main () {

    int a[] = {1,2,3,0};
    int b[] = {4,0,6,11};
    int c[] = {7,8,0,12};
    int d[] =  {13,14,15,16};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<int> bv (b,b+sizeof(b)/sizeof(b[0]));
    vector<int> cv (c,c+sizeof(c)/sizeof(c[0]));
    vector<int> dv (d,d+sizeof(d)/sizeof(d[0]));
    //vector< vector<int> > v (4)/sizeof();
    vector< vector<int> > v;
    //v[0] (a,a+sizeof(a)) ;
    v.push_back(av) ;
    v.push_back(bv) ;
    v.push_back(cv) ;
    v.push_back(dv) ;
    
    setZeroes (v);
}
