#include<iostream>
#include<vector>
#include <sstream> 
#include <map> 
using namespace std;


void print_path_vec(vector<int>&path,vector< vector<int> >&op_path) {

    //if (u_map.find(path) == u_map.end() ) {
        op_path.push_back(path);
    //}
}



bool find(vector<int> &num, int start, int end, int target) {
    for(int i = start; i < end; i++) {
        if(num[i] == target) {
            return true;
        }
        return false;
    }
}

void do_exchange_vec (vector<int> &input,int i,int j)  {
    int temp = input[i] ;
    input[i] = input[j];
    input[j] = temp;
}

void vec_permute(vector<int>& path,int k,int solution_size
        ,vector< vector<int> >& op_path) {
        //,vector<int>& tmp_path) {
    if ( k == (solution_size -1)) {
        //op_path.push_back(tmp_path);
        op_path.push_back(path);
    }else {
        k = k + 1;
        //iterate over the candiate 
        for (int i = k;i < path.size() ;i++) {
            if (i == k || !find(path,k,i,path[i]) ) {
                do_exchange_vec (path,i, k) ;
                //tmp_path.push_back(path[k]);
                //vec_permute(path,k,solution_size,op_path,tmp_path);    //(n-1)!
                vec_permute(path,k,solution_size,op_path);    //(n-1)!
                //tmp_path.pop_back();
                do_exchange_vec (path,k,i) ; //clean up
            }
        }
    }
}


vector<vector<int> > permuteUnique(vector<int> &num) {
    vector< vector<int> >op_vec;
    vector<int> tmp_path;
    int n = num.size();
    //vec_permute (num,-1,n,op_vec,tmp_path);
    vec_permute (num,-1,n,op_vec);
    return op_vec;
}

int main () {
    
    int A[] = {1,1,2};
    vector<int> a (A,A+sizeof(A)/sizeof(A[0]));
    vector < vector<int> > result = permuteUnique (a);
    int result_len = result.size();
    cout << result_len << endl;
    for (int i=0;i<result_len ;i++) {
        int in_len = result[i].size();
        for (int j=0;j<in_len;j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    //cout << str_t << endl;
}

