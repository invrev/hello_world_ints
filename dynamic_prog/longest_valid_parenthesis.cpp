#include<iostream>
#include<string>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    stack <int> left_index_stack;
    int len = s.length();
    int max_len = 0;
    int latest_left_index = -1;
    int i = 0;
    while (i < len) {
        if (s[i] == '(') {
            //case for consecutive subtring ()()()
            left_index_stack.push(i);
        } else {
            if (!left_index_stack.empty() && s[left_index_stack.top()] == '(' ) {
                left_index_stack.pop();
                int latest_left_index = -1;
                if (!left_index_stack.empty()) {
                    latest_left_index = left_index_stack.top();
                }
                max_len = max (max_len,(i - latest_left_index) );
            } else {
                left_index_stack.push(i);
            }
        }
        i++;
    }
    return max_len;
}

int main () {
    
    string str_ = "(()()";
    int len = longestValidParentheses (str_);
    cout << "the max len = " << len << endl;


    string str1 = "(()))()";
    len = longestValidParentheses (str1);
    cout << "the max len = " << len << endl;

    string str2 = "((())))(((";
    len = longestValidParentheses (str2);
    cout << "the max len = " << len << endl;

}
