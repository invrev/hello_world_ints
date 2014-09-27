#include<iostream>

struct bst {
    struct bst* left;
    struct bst* right;
    int data;
    bst (int x) : data(x), left(NULL),right(NULL) {}
};


bst* create_node (int a_data) {
   bst* tmp_node = 0;
   tmp_node = new bst(a_data);
   return (tmp_node);
}

void augment_left_tree (bst* root) {
   if (root == 0)  {
       return ;
   }else {
        augment_left_tree(root->left);
        //augment_left_tree(root->right);
        if (root->left == 0) {
         root->left = create_node(root->data);
        }else {
            tree_t *tmp_node = 0;
            tmp_node = create_node(root->data);
            tmp_node->left = root->left;
            root->left = tmp_node;
        }
   }
}
