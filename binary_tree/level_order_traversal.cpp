#include<iostream>

//Level order traversal using recursion
void levelOrder_helper(TreeNode* root, int level, vector<vector<int>>& result){
        if(!root) return;
        if(result.size() <= level){
            vector<int> tmp;
            result.push_back(tmp);
        }
        result[level].push_back(root->val);
        levelOrder_helper(root->left, level+1, result);
        levelOrder_helper(root->right, level+1, result);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    levelOrder_helper(root, 0, result);
    return result;
}
