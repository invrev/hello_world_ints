#include<iostream>

struct bst {
    int val;
    struct bst* left;
    struct bst* right;
}

//Count number of nodes in BST
int count_no_nodes(bst* root) {
    if (root == 0) {
        return (0);
    }else {
        //D&C use divide = 2
        //conquer = add the elements
        //consider a tree with root,left and right
        int l_node_length = count_no_nodes(root->left) ;
        int r_node_length = count_no_nodes(root->right) ;
        return (l_node_length + r_node_length + 1);
        //return (count_no_nodes(root->left)+ 1 + count_no_nodes(root->right));
    }
}

int main () {

    bst* root = 0;
    count_no_of_nodes(root);
}
