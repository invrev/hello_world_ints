#include<iostream>

struct bst {
    struct bst* left;
    struct bst* right;
    int data;
}


int total_cost_tree_sum(bst* root) {
    if (root == 0) {
        return 0;
    }else {
        int left_sum = total_cost_tree_sum(root->left);
        int right_sum = total_cost_tree_sum(root->right);
        return (left_sum + right_sum + root->data);
    }
}
