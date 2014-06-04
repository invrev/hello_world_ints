#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Determine string contain all the unique charcters or not no addition ds
//O(n^2) w/o any additional DS
void check_uniqueness (string input_str) {
    int len = input_str.length();
    int is_unique = 1;
    for (int i=0;i<len;i++) {
        if (is_unique == 0) {
            break; 
        }
        for (int j=i+1;j<len;j++)  {
            if (input_str[i] == input_str[j]) {
               cout << "the string  " << input_str << " did not contain unique characters." << endl;
               is_unique = 0;
               break;
            }
        }
    }

    if (is_unique == 1) {
        cout << "the string  " << input_str << " contain unique characters." << endl ;
    }
}

//Reverse C-style string
void revrse_c_style_str (const char *str) {
    int len = 0; 
    cout << "the reverse of the str = " << str << endl;
    while (str[len] != 0) {
       len += 1; 
    }
    while (len >= 0) {
        cout << str[len] ;
        len -= 1;
    }
    cout << endl;
}

//Determine wheather 2 string are anagram
void is_anagram (string first,string second) {
    string temp1 = first;
    string temp2 = second;
    int f_len = first.length();
    int s_len = second.length();
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    
    if (first == second) {
        cout << "the strings " << temp1 << " and " << temp2 << " are anagrams of each other" << endl;
    } else {
        cout << "the strings " << temp1 << " and " << temp2 << " are not anagrams of each other" << endl;
    }

}

//Remove the duplicate char w/o extra space

void remove_dup_char (string given_str) {
   cout << " given str = " << given_str << endl;
    int len = given_str.length();
    for (int i=0;i<len;i++) {
        for (int j=i+1;j<len;j++) {
            if (given_str[i] == given_str[j] && given_str[j] != '1') {
                 given_str[j] = '1';
            }
        }
    }
   cout << " the new uniq str = " << given_str << endl;
   int start_index = -1;
   int end_index = 0;
   int current_ptr = 0;
   for (int i=0;i<len;i++) {
       if (given_str [i] == '1' && start_index == -1)  {
            start_index = i; 
            end_index = i;
       } else if (given_str [i] == '1') {
            end_index += 1;
       } else {
            if (start_index != -1) {
                given_str[start_index] = given_str[i];
                start_index += 1;
                end_index += 1;
                given_str[i] = '1';
            }
       }
   }
   cout << " the new uniq str = " << given_str << endl;
}

//replace all the spaces with %20
void replace_spaces_with_per_twenty(string given_str) {
   
    int len = given_str.length();
    int start = 0;
    int end = 0;
    string replaced_str = "";
    for (int i=0;i<len;i++)  {
        if (given_str[i] == ' ') {
            end = i;
            //consecutive spaces will have the 0 length so return string with 0 length
            string temp_str = given_str.substr(start, (end-start)) ;
            temp_str += "%20";
            replaced_str += temp_str ;
            start = end+1;
        }
    }
    if (end < (len-1)) {
        string temp_str = given_str.substr(start, (len-start)) ;
        replaced_str += temp_str ;
    }

    cout << "the replaced str = " << replaced_str << endl;
}


void do_swap (int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}


void print_2_d_array(int mat[][4],int len) {
    for (int i=0;i<len;i++) {
        for (int j=0;j<len;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

//Rotate the matrix by  90.
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
    check_uniqueness ("HAH");
    check_uniqueness ("ABCDEFR");
    revrse_c_style_str ("ABCDEF");
    is_anagram ("ABA","ABA");
    is_anagram ("ALGORITHM","LOGARITHM");
    is_anagram ("GORITHM","GARITHM");
    remove_dup_char ("ABADEAG");
    remove_dup_char ("ABAADEAG");

    replace_spaces_with_per_twenty ("Hi  hello test rma");
    replace_spaces_with_per_twenty ("Hi hello test ");
    
    //int mat_1 [][3] = {
    //     {1,2,3}
    //     ,{4,5,6}
    //     ,{7,8,9}
    //
    //};

    //rotate_mat_by_ninty_deg (mat_1,3,3);

    int mat_2 [][4] = {
         {1,2,3,0}
         ,{4,0,6,11}
         ,{7,8,0,12}
         ,{13,14,15,16}
    
    };
    
    rotate_mat_by_ninty_deg (mat_2,4,4);

    convert_row_col_to_zero(mat_2,4,4,3,3);
    
    cout << endl;

    convert_row_col_to_zero_with_bit_vector(mat_2,4,4,3,3);

}
