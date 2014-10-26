#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print_solution (string output,vector<string>& output_store) {
    //cout << output << endl;
    output_store.push_back(output);
}

void telephone_enumerate (string& input,int k,int solution_size
        ,string& output,string telephone_dict[],int char_start,vector<string>& output_store) {
    if (k == (solution_size-1) ) {
        print_solution(output,output_store);
    } else {
        k = k + 1;
        char_start = 0;
        int c_number = input[k] - '0';
        int len_ = telephone_dict[c_number].size();
        string tmp_str = telephone_dict [c_number];
        //cout << tmp_str  << endl;
        for (int i = char_start ;i < len_; i++) {
           //new_str = output.substr();
            output[k] = tmp_str[i];
            telephone_enumerate (input,k,solution_size,output
                    ,telephone_dict,char_start++,output_store);
        }
    }
}

vector<string> letterCombinations(string digits) {
    string a[9] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int k = -1;
    vector<string> output_store;
    int sol_size = digits.size();
    string output ;
    for (int i=0;i < sol_size ;i++) {
        output.append("x");
    }
    telephone_enumerate (digits,k,sol_size,output,a,0,output_store);
    return output_store;
}


int main () {

    //string a[9] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //int number[] = {4,5,6,7};
    //string output = "xxxx";
    //int sol_size = 4;
    //int k = -1;
    //vector<string> output_store;
    //telephone_enumerate (number,k,sol_size,output,a,0,output_store);
    string digits = "234";
    vector<string> str_vec = letterCombinations (digits);
    //int len = sizeof(number)/sizeof(number[0]);
    //for (int i=0;i<len;i++) {
    //    int c_number = number[i];
    //    int len_ = a[c_number].size();
    //    string tmp_str = a[c_number];
    //    for (int i=0;i < len_;i++) {
    //        cout << tmp_str.substr(i,1) << " ";
    //    }
    //    cout << endl;
    //}
    //for (int i=0;i<9;i++)
    //{
    //    cout <<  a[i] << ",";

    //}
    //cout << endl;
}

