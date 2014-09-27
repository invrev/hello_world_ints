#include<iostream>

struct bst {
    struct bst* left;
    struct bst* right;
    int val;
};

bool is_valid_bst (bst* root,int max,int min) {
        if (root) {
            cout << "root->data = " << root->data << " min = " << min  << " max " <<  max << endl;
            if (is_valid_bst (root->left,max,min) == false ) {
                return false;
            }
            //if (root->data < min || root->data > max) {
            if (root->data < t_min || root->data > t_max) {
                cout << "returned false" << endl;
                return false;
            } else {
                //min = root->data;
                t_min = root->data;
                //cout << "data assignment = " << min << endl;
            }
            return (is_valid_bst (root->right,max,min));
        } else {
            cout << "returning true comming from stack" << endl;
            return true;
        }
}

