#include<iostream>
#include<vector>
#include <sstream> 
#include <map> 
using namespace std;


void print_path_vec(vector<int>&path,vector< vector<int> >&op_path
        ,map< vector<int>,bool>& u_map) {

    if (u_map.find(path) == u_map.end() ) {
        op_path.push_back(path);
        //u_map[path] = true;
        u_map.insert( pair< vector <int>, bool > (path,true) );
    }
}



void do_exchange_vec (vector<int> &input,int i,int j)  {
    int temp = input[i] ;
    input[i] = input[j];
    input[j] = temp;
}

void vec_permute(vector<int>& path,int k,int solution_size
        ,vector< vector<int> >&op_path,map< vector<int>,bool>& u_map) {
    if ( k == (solution_size -1)) {
        print_path_vec(path,op_path,u_map);
    }else {
        k = k + 1;
        //iterate over the candiate 
        for (int i = k;i < path.size() ;i++) {
            do_exchange_vec (path,i, k) ;
            vec_permute(path,k,solution_size,op_path,u_map);    //(n-1)!
            do_exchange_vec (path,k,i) ; //clean up
        }
    }
}


vector<vector<int> > permuteUnique(vector<int> &num) {
    map< vector<int> ,bool> u_map;
    vector< vector<int> >op_vec;
    int n = num.size();
    vec_permute (num,-1,n,op_vec,u_map);
    return op_vec;
}



string getPermutation (int n,int k) {
    vector<int> vec_i(n);
    vector< vector<int> >op_path;
    for (int i=1;i<=n;i++) {
        vec_i[i-1] = i;
    }
    map< vector<int> ,bool> u_map;
    vec_permute (vec_i,-1,n,op_path,u_map);
    int l = op_path.size();
    string result = "";
    //ostringstream convert;   
    //for (int i=0;i<l;i++) {
    //    result = "";
    //int ir = op_path[k-1].size();
    //for (int j=0;j<ir;j++) {
    //    //cout << op_path[i][j] << "," ;
    //    convert << op_path[k-1][j]; 
    //    convert << ",";
    //}
    //result += convert.str();
    //result = result.substr(0, result.length() -1 );
    ////cout << result ;
    //convert.str("");
    //cout << endl;
    //}
    return result;
}



int main () {
    //string str_t = getPermutation (2,2);
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

