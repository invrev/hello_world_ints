#include<iostream>
#include<vector>
using namespace std;

//Thinking about there is an opt[] array, each element in the array is a vector<vector>. We do DP from opt[0] to opt[target].

// base case

//opt[0] = [[]]

// iteration

//opt[i] =
//
//add candidates[j] to each list in opt[i-candidates[j]] if i > candidates[j] .Add each list to opt[i]
//
//create candidates[j] as a new vector if i == candidates[j] .Add this list to opt[i]


vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        vector< vector< vector<int> > > combinations(target + 1, vector<vector<int>>());
        combinations[0].push_back(vector<int>());
        for (auto& score : candidates) {
            for (int j = score; j <= target; j++) {
                if (combinations[j - score].size() > 0) {
                    auto tmp = combinations[j - score];
                    for (auto& s : tmp)
                        s.push_back(score);
                    combinations[j].insert(combinations[j].end(), tmp.begin(), tmp.end());
                }
            }
        }
        auto ret = combinations[target];
        for (int i = 0; i < ret.size(); i++)
            sort(ret[i].begin(), ret[i].end());
        return ret;
}




