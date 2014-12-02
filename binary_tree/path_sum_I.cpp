#include<iostream>
using namespace std;


bool hasPathSum(TreeNode *root, int sum) {
    if(root == NULL)return false;
    if(root->left == NULL && root->right == NULL && root->val == sum)
        return true;
    if(root->left && hasPathSum(root->left, sum - root->val))
        return true;
    if(root->right && hasPathSum(root->right, sum - root->val))
        return true;
    return false;
}



bool hasPathSum(TreeNode *root, int sum) {
    if (root) {
        sum = sum - (root->val);
        if (sum  == 0 && root->left == 0 && root->right == 0) {
            return true;
        } else if (sum != 0 && root->left == 0  && root->right == 0) {
            return false;
        }else  { 
            //Parallel traversing of the binary tree by storing the result in the variable "sum"
            return (hasPathSum (root->left,sum) || 
            hasPathSum (root->right,sum));
        }
        } 
    else {
            return false;
    }
}
