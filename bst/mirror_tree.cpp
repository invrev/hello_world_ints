#include<iostream>

struct bst {
    int val;
    struct bst* left;
    struct bst* right;
}


//Print mirror image of the BST
void mirror_tree (bst* root) {
    if(root == 0) {
        return;
    } else {
      tree_t *tmp_node = root->left;  
      root->left = root->right;
      root->right = tmp_node;
      mirror_tree(root->left);
      mirror_tree(root->right);
    }
}
