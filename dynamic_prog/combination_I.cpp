#include<iostream>
#include<vector>
using namespace std;

//First, sort the candidates and remove duplicates, I did this with set using 2 line

//Second, call the depth-first-search function to generate the result. In the function, I marked the largest element has been used, and only attempt to use the same or larger element when doing recursive calls which makes the result meet the ordering restriction.

void dfs(vector<int> &can, int t, vector<int> &cur, int k, vector<vector<int> > &res) {
        if(t == 0) {
            res.push_back(cur);
            return;
        }
        if(can[k] <= t) {
            for(int i = k; i < can.size() and can[i] <= t; i++) {
                cur.push_back(can[i]);
                dfs(can, t - can[i], cur, i, res);
                cur.pop_back();
            }
        }
}
    
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        if(candidates.size() == 0) return res;
        set<int> dedup(candidates.begin(), candidates.end());
        candidates = vector<int>(dedup.begin(), dedup.end());
        vector<int> tmp;
        dfs(candidates, target, tmp, 0, res);
        return res;
}

int main () {

}
