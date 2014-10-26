#include<iostream>
#include<stdlib.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Same as verify BST in that we need to keep track of maximum and minimum
//Eg. {1,#,2,#,3}
//Eg. {1,2,2,3,#,#,3,4,#,#,4} 
//             1
//         2       2 
//      3    #  #     3
//   4    #        #   4

int max_depth (TreeNode *root,bool &result) {
    if (!root) {
        return 0;
    } 
    int l_ht = max_depth (root->left,result) + 1;
    int r_ht = max_depth (root->right,result) + 1;
    if (abs (l_ht - r_ht) > 1 )  {
        result = false;
    }
    return max (l_ht,r_ht) ;
}


bool isBalanced(TreeNode *root) {
    bool result = true;
    max_depth (root,result);
    return result;
}


int height_of_bt (TreeNode *root) {
    if (!root) {
        return 0;
    } if (root->left) {
        return (1 + height_of_bt (root->left) );
    } if (root->right) {
        return (1 + height_of_bt(root->right) );
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    }
}

bool isBalanced0(TreeNode *root) {
    if (!root)  {
        return true;
    } else {
        int left_ht = height_of_bt (root->left);
        int right_ht = height_of_bt (root->right);
        //cout <<  " (" << left_ht << "," <<  right_ht  <<  ") " << endl;
        if ( abs(left_ht - right_ht) <= 1 ) {
            return true;
        } else {
            return false;
        }
    }
}

int main () {

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    bool ans = isBalanced (root);
    cout << "The ans is " << ans << endl ;

}
