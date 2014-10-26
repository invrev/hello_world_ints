#include<iostream>
using namespace std;

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
    struct TreeNode(int x) : left (NULL),right(NULL),val(x) {}
};

//VERBOSE and wrong
bool bstHelper (TreeNode* root,int min,int max) {
    if (root == 0) {
        return true;
    } else {
        if (root->left) {
            if (root->val > root->left->val && root->val < max ) {
                min = root->left->val;
                return bstHelper(root->right,min,max);
            } else {
                return false;
            }
        }
        if (root->right) {
            if (root->val < root->right->val && root->val > min) {
                max = root->right->val;
                return bstHelper(root->right,min,max);
            } else {
                return false;
            }
        }
    }
}

bool bstHelper0 (TreeNode* root,int min,int max) {
    if (root == 0) {
        return true;
    } else {
        if (root->val < min || root->val > max) {
            return false;
        } 
        return ( bstHelper0 (root->left,min,root->val+1)  &&
                bstHelper0 (root->right,root->val-1,max) ) ;
    }
}
bool isValidBST(TreeNode *root) {

    return bstHelper0 (root,INT_MIN,INT_MAX);
}


//BST traversal always returns ascending order of elements
//NOTE : to update the parameter prev everytime used reference
bool inorderBST (TreeNode* root,int& prev) {
    if (root == 0) {
        return true;
    } else {
        //Travserse left  (L-D-R)
        bool left_b = inorderBST (root->left,prev);
        //case {1,0}
        if (prev != INT_MIN && prev >= root->val) {
            return false;
        } 
        prev = root->val;
        bool right_b = inorderBST (root->right,root->val);
        return (left_b  && right_b);
    }
}

bool isValidBST0(TreeNode *root) {
    //start from the smallest element
    int prev = INT_MIN;
    return inorderBST(root,INT_MIN);
}

int main () {
    TreeNode *root = NULL;
      
}
