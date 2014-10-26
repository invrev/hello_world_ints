#include<iostream>
#include<vector>
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


void print_solution  (string input,vector<string>& output) {
    //cout << "input = " << input << endl;
    output.push_back(input);
    //cout << input << endl;
}

//Individual solution size = 2 * n
//# of left parenthesis  = n and right parenthesis = n
void enum_parenthesis (string input,int k,int c,int solution_size,vector<string>& output) {
    bool is_continue = true;
    if (k == (solution_size - 1) ) {
        print_solution (input,output) ;
    } else {
        k = k + 1; 
        for (int i = 0;i< c;i++) {
            add_parenthesis(input,k,i,solution_size,is_continue);  
            if (is_continue == true) {
                enum_parenthesis (input,k,c,solution_size,output);
            }
        }
    }
}

vector<string> generateParenthesis(int n) {
    //enum_parenthesis ("XXXX",-1,2,4);
    int total_no_sol = n * 2;
    int set_size = n - 1;
    vector<string> output_vec;
    string a;
    for (int i=0;i<total_no_sol;i++) {
        a.append("x");
    }
    enum_parenthesis (a,-1,set_size,total_no_sol,output_vec);
    for (int i=0;i<output_vec.size();i++) {
       cout <<  output_vec[i] << endl;
    }
    return output_vec;
}


int main () {
    vector<string> output_vec =  generateParenthesis(3);
}
