#include<iostream>
#include<vector>
using namespace std;

void printSol (vector<int>& result) {
    for (auto &i:result) {
        cout << i << ",";
    }
    cout << endl;
}

//Get the permutation with repeated #s
void getPermutation (vector<int>&input,vector<int>& visited
        ,int k,vector<int>&result,vector<vector<int> >&op) {

    if (k == input.size()) {
        op.push_back(result);
        printSol(result);
        return;
    }
    //Generate candidates
    for (int i=0;i<input.size();i++) { //i : # of candiates
        if (visited[i] == 0) {
            visited[i] = 1;
            result.push_back(input[i]);
            //NOTE : for each level K will have 3 candidates (i) with choices either pick or not pick 
            getPermutation (input,visited,k+1,result,op); //k : # of levels
            visited[i] = 0;
            result.pop_back();
        }
    }
}


//Get the permutation with repeated #s
void getPermutationWoRepeat (vector<int>&input,vector<int>& visited
        ,int k,vector<int>&result,vector<vector<int> >&op) {

    if (k == input.size()) {
        op.push_back(result);
        printSol(result);
        return;
    }
    //Generate candidates
    for (int i=0;i<input.size();i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            result.push_back(input[i]);
            getPermutationWoRepeat (input,visited,k+1,result,op);
            //If successive candidates are same then increase the # of candidates
            while (i < input.size() && input[i] == input[i+1]) {
                i++;
            }
            visited[i] = 0;
            result.pop_back();
        }
    }
}


void test(int a[],int n) {
    vector<int> av(a,a+n);
    vector<int> visited(av.size(),0);
    vector<int> result;
    vector<vector<int> > op;
    getPermutation (av,visited,0,result,op);
}


void test1(int a[],int n) {
    vector<int> av(a,a+n);
    vector<int> visited(av.size(),0);
    vector<int> result;
    vector<vector<int> > op;
    getPermutationWoRepeat (av,visited,0,result,op);
}


int main () {
    int a[] = {1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    //test(a,n);
    test1(a,n);
    int b[] = {1,1,2};
    n = sizeof(b)/sizeof(b[0]);
    //test(b,n);
    test1(b,n);
}
