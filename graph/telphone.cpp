#include<iostream>
#include<string>
#include<vector>
using namespace std;

//digits is the input and dictinary of words is the candidates
void enum_phone (string& input,int k,vector<string>&candi,string &solution,vector<string>& solution_store) {
    if (k == input.size() - 1) {
        //find the solution
        cout << solution << endl;
    } else {
        //iterate over digits
        k = k + 1;
        //iterate over candidates
        //cout << candi[input[k] - '0'] << endl;
        string possible_cand = candi[input[k] - '0'];
        for (int i=0;i<possible_cand.length();i++) {
            solution.push_back(possible_cand[i]);  //c++11
            //op[k] = possible_cand[i];
            enum_phone(input,k,candi,solution,solution_store);
            solution.pop_back();
        }
    }
}

int main ()  {
    string keypad_str[] = {"","abc","def","gh"};
    vector<string> keypad(keypad_str,keypad_str+sizeof(keypad_str)/sizeof(keypad_str[0]));
    string input = "123";
    int k = -1;
    vector<string> solution_store;
    string solution;
    //for (int i=0;i<input.length();i++) {
    //    output.append("x");
    //}
    enum_phone (input,k,keypad,solution,solution_store);
}
