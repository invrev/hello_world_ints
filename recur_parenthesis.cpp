#include<iostream>
using namespace std;

void add_parenthesis  (string& input,int k,int c,int solution_size,bool& is_continue) {
    is_continue = true;
    if (c == 0) {
        input [k] = '(';
    } else {
        input [k]  = ')';
    }
    //Pruning
    int left = 0,right = 0;
    for (int i=0;i< solution_size;i++) {
        if  (input[i] == '(' ) {
            left += 1;
        }else if (input[i] == ')' ) {
            right += 1;
        }
    }
    int number_parenthesis  = solution_size / 2;
    //cout << number_parenthesis  << " left = " << left << " right = " << right << endl;
    //Prune conditions
    if ( (left > number_parenthesis)  or (right > number_parenthesis) or (left < right)) {
        is_continue = false;
    } 
}


void print_solution  (string input) {
    //cout << "input = " << input << endl;
    cout << input << endl;
}

//Individual solution size = 2 * n
//# of left parenthesis  = n and right parenthesis = n
void recur_parenthesis (string input,int k,int c,int solution_size) {
    bool is_continue = true;
    if (k == (solution_size - 1) ) {
        print_solution (input) ;
    } else {
        k = k + 1; 
        for (int i = 0;i< c;i++) {
            add_parenthesis(input,k,i,solution_size,is_continue);  
            if (is_continue == true) {
                recur_parenthesis (input,k,c,solution_size);
            }
        }
    }
}

int main () {
    //recur_parenthesis ("XXXX",-1,2,4);
    recur_parenthesis ("XXXXXX",-1,2,6);
}
