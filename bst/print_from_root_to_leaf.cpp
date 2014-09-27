#include<iostream>
struct bst {
    int data;
    struct bst* left;
    struct bst* right;
};

//Declared global
int path [100];

//traverse in DLR passion and store the root
void print_all_root_leaf_path(bst* root,int path_len) {
    if (root != 0) {
      path[path_len] = root->data;
      cout << "Inseritng data = "<< path[path_len] << "at location = " << path_len << "root_left = " <<  root->left << "and root_right = " << root->right  << endl;
      path_len = path_len + 1;
      //Added base case to print the path from root to leaf
      if (root->left == 0 && root->right == 0) {
            int i = 0;
            cout << "print r_L started " << endl;
            for (i=0;i<path_len;i++) {
                cout << path[i] << " ";
            }
      }
      //print_all_root_leaf_path(root->left,path,path_len);
      //print_all_root_leaf_path(root->right,path,path_len);
      print_all_root_leaf_path(root->left,path_len);
      print_all_root_leaf_path(root->right,path_len);
    }
}
