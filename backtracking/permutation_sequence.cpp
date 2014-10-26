#include<iostream>
#include<vector>
#include <sstream> 
using namespace std;

void print_path_vec(vector<int>&path,vector< vector<int> >&op_path) {
    op_path.push_back(path);
}

void do_exchange_vec (vector<int> &input,int i,int j)  {
    int temp = input[i] ;
    input[i] = input[j];
    input[j] = temp;
}

void vec_permute(vector<int>& path,int k,int solution_size,vector< vector<int> >&op_path) {
    if ( k == (solution_size -1)) {
        print_path_vec(path,op_path);
    }else {
        k = k + 1;
        //iterate over the candiate 
        for (int i = k;i < path.size() ;i++) {
            do_exchange_vec (path,i, k) ;
            vec_permute(path,k,solution_size,op_path);    //(n-1)!
            do_exchange_vec (path,k,i) ; //clean up
        }
    }
}

string getPermutation (int n,int k) {
    vector<int> vec_i(n);
    vector< vector<int> >op_path;
    for (int i=1;i<=n;i++) {
        vec_i[i-1] = i;
    }
    vec_permute (vec_i,-1,n,op_path);
    int l = op_path.size();
    string result = "";
    ostringstream convert;   
    //for (int i=0;i<l;i++) {
    //    result = "";
    int ir = op_path[k-1].size();
    for (int j=0;j<ir;j++) {
        //cout << op_path[i][j] << "," ;
        convert << op_path[k-1][j]; 
        convert << ",";
    }
    result += convert.str();
    result = result.substr(0, result.length() -1 );
    //cout << result ;
    convert.str("");
    //cout << endl;
    //}
    return result;
}

int main () {
    string str_t = getPermutation (2,2);
    //cout << str_t << endl;
}

