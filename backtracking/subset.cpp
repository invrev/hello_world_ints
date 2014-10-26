#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

void print_subset(vector<int> a,int k,vector<int>& input_subset
        ,vector< vector<int> >& output_subset) {
    vector<int> tmp;
    for (int i=0;i<=k;i++) {
        if ( a[i] == 0) {
            tmp.push_back(input_subset[i]);
        }
    }
    output_subset.push_back(tmp);
}

void subset_enumerate (vector<int>& a ,int k,int solution_size
        ,vector<int>& input_subset,vector< vector<int> >& output_subset) {
    if (k == (solution_size-1) ) {
       print_subset(a,k,input_subset,output_subset);
    } else {
        k = k + 1;
        subset_enumerate (a,k,solution_size,input_subset,output_subset); //(n-1) !
        a[k] = 1;                                                        //Flip a[k]
        subset_enumerate (a,k,solution_size,input_subset,output_subset); //(n-1)!
        a[k] = 0;
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    
    vector<vector<int> >output_subset;
    int n = S.size();
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        a[i] = 0;
    }
    subset_enumerate (a,-1,n,S,output_subset);
    unordered_map <int,vector<int>>  vec_map ;
    for (int i=0;i<output_subset.size();i++) {
       vector<int> inner_vec = output_subset[i];
       int l = inner_vec.size();
       //sort(inner_vec.begin(),inner_vec.end());
       for (int i=0;i<l;i++) {
           cout << inner_vec[i] << ",";
       }
       cout << endl;
    }

    return output_subset;
}

int main () {
    int a[] = {1,2,2};
    vector<int> s (a,a+sizeof(a)/sizeof(a[0]));
    vector< vector<int> > result = subsets (s);
    //vector< vector<int> > result = distinct_subsets (s);
}
