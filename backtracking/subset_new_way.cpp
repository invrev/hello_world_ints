#include<iostream>
#include<vector>

using namespace std;

//I make recursive call trying to go over the vector from left to right. 
//For each number in vector, it has to options: show in the subset, or not show in the subset. 
//There for each recursive call will generate two more recursive calls. And in the base case, we add the vector to result set.


void subsets_helper(vector<int> tmpVec, vector<vector<int>>& result, vector<int>& S, int level){
    if(level==0) result.push_back(tmpVec);
    else{
        vector<int> newVec0 = tmpVec; 
        newVec0.push_back(S[S.size()-level]); //1.element is in the solution set
        vector<int> newVec1 = tmpVec;         //2.element is not in the solution set
        subsets_helper(newVec0, result, S, level-1);
        subsets_helper(newVec1, result, S, level-1);
    }
}

vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> result;
    vector<int> tmpVec;
    subsets_helper(tmpVec, result, S, S.size());
    return result;
}

int main () {

    int a[] = {1,2,2};
    vector<int> s (a,a+sizeof(a)/sizeof(a[0]));
    vector< vector<int> > result = subsets (s);
}

