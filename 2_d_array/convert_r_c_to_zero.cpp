#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void print_2_d_array(int mat[][4],int len) {
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}




void convert_row_col_to_zero_with_bit_vector (int mat[][4],int len,int width,int i,int j) {
    
        //Though @the machine level bit represented as either little or big endian it has no effect on shift operation
        unsigned int row_store = 0;
        unsigned int col_store = 0;

        cout << "Given array " << endl;
        print_2_d_array (mat,4);

        for (int i=0;i<len;i++) {
            for (int j=0;j<len;j++) {
                if (mat[i][j] == 0) {
                    unsigned int mask = 1;
                    row_store |=  (mask << i);
                    col_store |=  (mask << j);
                }
            }
        }
        for (int i=0;i<len;i++) {
            if (row_store & 1 == 1) {
                int k = 0;
                while (k < width) {
                     mat[i][k] = 0;
                     k += 1;
                }
            }
            row_store = row_store  >> 1;
        }
        for (int j=0;j<width;j++) {
            if (col_store & 1 == 1) {
                int k = 0;
                while (k < len) {
                     mat[k][j] = 0;
                     k += 1;
                }
            }
            col_store = col_store  >> 1;
        }

        cout << "output array " << endl;
        print_2_d_array (mat,4);

}


void convert_row_col_to_zero(int mat[][4],int len,int width,int i,int j) {
         
        cout << "Given array " << endl;
        print_2_d_array (mat,4);
        
        int row_store[len];
        int col_store[width];
        for (int i=0;i<len;i++) {
            row_store[i] = 0;
        }
        for (int j=0;j<width;j++) {
            col_store[j] = 0;
        }
        for (int i=0;i<len;i++) {
            for (int j=0;j<len;j++) {
                if (mat[i][j] == 0) {
                    row_store[i] = 1;
                    col_store[j] = 1;
                }
            }
        }

        for (int i=0;i<len;i++) {
            if (row_store[i] == 1) {
                int k = 0;
                while (k < width) {
                     mat[i][k] = 0;
                     k += 1;
                }
            }
        }


        for (int i=0;i<width;i++) {
            if (col_store[i] == 1) {
                int k = 0;
                while (k < len) {
                     mat[k][i] = 0;
                     k += 1;
                }
            }
        }

    cout << "output array " << endl;
    print_2_d_array (mat,4);

}

int main () {

    int mat_2 [][4] = {
         {1,2,3,0}
         ,{4,0,6,11}
         ,{7,8,0,12}
         ,{13,14,15,16}
    
    };
    
    convert_row_col_to_zero(mat_2,4,4,3,3);
    cout << endl;
    convert_row_col_to_zero_with_bit_vector(mat_2,4,4,3,3);




}
