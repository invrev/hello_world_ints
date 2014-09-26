#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<sstream>
using namespace std;

int eval_expression (vector<string>& tokens) {
        int len = tokens.size();
        stack<string> input_stack;
        for (int i=0;i<len;i++) {
            int token_size = tokens[i].length() ;
            //cout << "token_size = " << token_size  << endl;
            if ( token_size == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' 
                || tokens[i][0] == '*' || tokens[i][0] == '/') ) { 
                string first_operand_str = input_stack.top();
                input_stack.pop();
                string second_operand_str = input_stack.top();
                input_stack.pop();
                int first_operand = atoi(first_operand_str.c_str());
                int second_operand = atoi(second_operand_str.c_str());
                int result = 0 ;
                if (tokens[i][0] == '+') {
                    result  = first_operand + second_operand ;
                } else if (tokens[i][0] == '-') {
                    result  = first_operand - second_operand ;
                } else if (tokens[i][0] == '*') {
                    result  = first_operand * second_operand ;
                } else if (tokens[i][0] == '/') {
                    if (second_operand != 0) {
                        result  = first_operand / second_operand ;
                    }
                    result = 0;
                }
                stringstream out;
                out << result ;
                string result_str = out.str();
                input_stack.push(result_str);

            } else {
                input_stack.push(tokens[i]);
            }
        }
        string result_str = input_stack.top();
        int result = atoi(result_str.c_str());
        return (result);
}

int main () {
    vector<string> input;
    //input.push_back("2");
    //input.push_back("1");
    //input.push_back("+");
    //input.push_back("3");
    //input.push_back("*");
    input.push_back("3");
    input.push_back("-4");
    input.push_back("+");

    int result = eval_expression(input);
    cout << "the result = " << result << endl;
    
}
