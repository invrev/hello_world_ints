#include<iostream>
#include<vector>
using namespace std;

void print_solution_set (vector<int>& input,vector<int>& candidates,vector<int>&solution) {
    cout << "{ " ;
    for (int i=0;i<candidates.size();i++) {
        if (candidates[i] == 0) {
            cout << input[i] << ",";
        }
    }
    cout << " }" ;
    cout << endl;
}

void generate_subset (vector<int>& input,vector<int>& candi,int k,vector<int>&solution) {
    if (k == input.size() - 1) {
        //update solution
        print_solution_set(input,candi,solution);
    } else {
        k = k + 1;
        //move for all 1
        generate_subset (input,candi,k,solution);
        candi[k] = 0;
        //move for all 0
        generate_subset (input,candi,k,solution);
        
        candi[k] = 1; //backtrack
    }
}


int main () {
    //given #s {1,2,3}
    //palindorme partioning/substring generation
    int a[] = {1,2,3};
    vector<int> input(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> solution;
    vector<int>candi(input.size(),1);
    int k = -1;
    generate_subset(input,candi,k,solution);
}

