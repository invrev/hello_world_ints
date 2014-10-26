#include<iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) {
    if (root) {
        return (max (1 + maxDepth(root->left),1 + maxDepth(root->right)));   
    } else {
        return 0;
    }
}

int main () {

}
