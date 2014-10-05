#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

//Use of map to avoid the duplicates
void print_subset_distinct(vector<int> a,int k,vector<int>& input_subset
        ,map <vector<int>,int>& output_map) {
    
    vector<int> tmp;

    for (int i=0;i<=k;i++) {
        if ( a[i] == 0) {
            tmp.push_back(input_subset[i]);
        }
    }
    map<vector<int>,int> :: iterator find_it = output_map.find(tmp) ;
    if (find_it == output_map.end()) {
        output_map.insert( pair<vector<int>,int>(tmp,1) );
    }
}

void subset_enumerate_distinct (vector<int>& a ,int k,int solution_size
        ,vector<int>& input_subset,map< vector<int>,int >& output_map) {
    if (k == (solution_size-1) ) {
      print_subset_distinct(a,k,input_subset,output_map);
    } else {
        k = k + 1;
        subset_enumerate_distinct(a,k,solution_size,input_subset,output_map); //(n-1) !
        a[k] = 1;                                                        //Flip a[k]
        subset_enumerate_distinct(a,k,solution_size,input_subset,output_map); //(n-1)!
        a[k] = 0;
    }
}

vector<vector<int> > distinct_subsets(vector<int> &S) {
    map< vector<int>,int > output_map;
    vector< vector<int> >output_subset;
    int n = S.size();
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        a[i] = 0;
    }
    subset_enumerate_distinct (a,-1,n,S,output_map);
    //map has iterator
    map < vector<int>,int >  :: iterator it = output_map.begin();
    while (it != output_map.end()) {
       vector<int> inner_vec = it->first;
       int l = inner_vec.size();
       output_subset.push_back(inner_vec);
       //sort(inner_vec.begin(),inner_vec.end());
       for (int i=0;i<l;i++) {
           cout << inner_vec[i] << ",";
       }
       it++;
       cout << endl;
    }
    return output_subset;
}

int main () {
    int a[] = {1,2,2};
    vector<int> s (a,a+sizeof(a)/sizeof(a[0]));
    vector< vector<int> > result = distinct_subsets (s);
}
