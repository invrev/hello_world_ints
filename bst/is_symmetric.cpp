#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSymmetricHelper (TreeNode* first,TreeNode *second) {

    if (!first && !second) {
        return true;
    } else if ( (!first && second) || (first && !second) )  {
        return false;
    } else if (first->val != second->val) {
        return false;
    } 
    return (isSymmetricHelper(first->left,second->right) 
            && isSymmetricHelper(first->right,second->left) );

}
bool isSymmetric(TreeNode *root) {

    if (root == NULL) {
        return true;
    }  
    return isSymmetricHelper (root->left,root->right);
    //else if (root->left == NULL && root->right == NULL) {
    //    return true;
    //} else if (root->left != NULL && root->right == NULL) {
    //    return false;
    //} else if (root->right != NULL && root->left == NULL) {
    //    return false;
    //} 
    //return ( root->left->val == root->right->val 
    //         && isSymmetric(root->left) 
    //         && isSymmetric (root->right) );
        
}

int main () {

}
