#include<iostream>
#include<vector>
using namespace std;


void printSol (vector<int>& result) {
    for (auto &i:result) {
        cout << i << ",";
    }
    cout << endl;
}

//Given vector and sum op all possible list of vectors with REPEATION
void getSubsetSum (vector<int>& input,int sum,int target,int k
        ,vector<int>& result,vector< vector<int> >& op) {

    //pruning
    if (sum > target) {
       return; 
    }
    if (sum == target) {
        op.push_back(result);
        printSol(result);
        return;
    }
    //Deciding # of candidates 
    for (int i=k;i<input.size();i++) {
        sum += input[i];
        result.push_back(input[i]);
        getSubsetSum (input,sum,target,i,result,op);
        sum -= input[i];
        result.pop_back();
    }
}


void getSubsetSumWoRepeat (vector<int>& input,int sum,int target,int k
        ,vector<int>& result,vector< vector<int> >& op) {

    //pruning
    if (sum > target) {
       return; 
    }
    if (sum == target) {
        op.push_back(result);
        printSol(result);
        return;
    }
    //Deciding # of candidates 
    for (int i=k;i<input.size();i++) {
        sum += input[i];
        result.push_back(input[i]);
        getSubsetSumWoRepeat(input,sum,target,i+1,result,op);
        sum -= input[i];
        result.pop_back();
        //Get the next candidate if successive candidates are equal
        while (i < input.size() && input[i] == input[i+1]) { 
            i++;
        }

    }
}


void test(int a[],int n,int sum) {
    vector<int> av(a,a+n);
    vector<int> visited(av.size(),0);
    vector<int> result;
    vector<vector<int> > op;
    getSubsetSum (av,0,sum,0,result,op);
}


void test1(int a[],int n,int sum) {
    vector<int> av(a,a+n);
    vector<int> visited(av.size(),0);
    vector<int> result;
    vector<vector<int> > op;
    getSubsetSumWoRepeat(av,0,sum,0,result,op);
}


int main () {
    int a[] = {1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    test(a,n,3);
    cout << "---------" << endl;
    test1 (a,n,3);
}
