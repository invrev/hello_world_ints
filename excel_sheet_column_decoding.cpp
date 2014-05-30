#include<iostream>
#include<string>
#include <math.h>

using namespace std;

void decode_xl_col (string xl_col) {
    int t_len = xl_col.length();
    int index = t_len - 1;
    int col_number = 0;
    int something_went_wrong = 0;
    for (int i=0;i<t_len;i++,index--) {
        char ind_char = xl_col[i];
        int rank =  ind_char - 'A';
        //NOTE : "A" = 1
        rank += 1;
        if (rank > 26) {
            something_went_wrong = 1;
            break; 
        }
        //cout << "the char " << ind_char << " rank = " << rank  << " index = " << index << endl;
        //limit A-Z
        int tmp_result = pow (25,index) * rank;
        col_number += tmp_result;
    }
    if (something_went_wrong == 1)  {
        cout << "something went wrong." << endl;
    } else {
        cout << "XL col = " << xl_col << " decoded value = " << col_number << endl;
    }

}

int main () {
    decode_xl_col("AB");
    decode_xl_col("AZ");
}



