#include<iostream>
#include<string>
using namespace std;

//atoi : Convert string into the int traverse from left to right
int return_atoi_l_to_r (string input_no) {
    int t_len = input_no.length();
    int actual_no = 0;
    for (int i=0;i<t_len;i++) {
       int str_no = input_no[i] - '0';
       actual_no = (actual_no * 10);
       actual_no += str_no;
    }
    cout << "the actual # from l to r = " << actual_no << endl;
    return (actual_no);
}

void string_do_reverse_inplace (string input_str) {
    int end = input_str.length();
    int start = 0;
    cout << "input string = " << input_str << endl;
    while (start <= end) {
        char temp = input_str[start];
        input_str[start] = input_str[end];
        input_str[end] = temp;
        start += 1;
        end -= 1;
    }
    cout << "reversed string = " << input_str << endl;
}

int return_atoi_r_to_l (string input_no) {
    int len = input_no.length();
    int factor = 1;
    int actual_no = 0;
    for (int i=len-1;i>=0;i--) {
        int str_no = input_no[i] - '0' ;
        actual_no += (factor * str_no);
        factor *= 10;
    }
    cout << "the actual # from r to l = " << actual_no << endl;
    return (actual_no);
}


int main () {
    return_atoi_r_to_l ("123");
    return_atoi_l_to_r ("123");
    string_do_reverse_inplace ("hi hello steve jobs");
}
