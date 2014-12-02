#include<iostream>
using namespace std;

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res;
    if(root == NULL)return res;
    vector<int> curres;
    curres.push_back(root->val);
    pathSumRecur(root, sum, curres, res);
    return res;
}

void pathSumRecur(TreeNode *root, int sum, vector<int> &curres, vector<vector<int> >&res) {
    if(root->left == NULL && root->right == NULL && root->val == sum) {
        res.push_back(curres);
        return;
    }
    if(root->left) {
        curres.push_back(root->left->val);
        pathSumRecur(root->left, sum - root->val, curres, res);
        curres.pop_back();
    }
    if(root->right) {
        curres.push_back(root->right->val);
        pathSumRecur(root->right, sum - root->val, curres, res);
        curres.pop_back();
    }
}
