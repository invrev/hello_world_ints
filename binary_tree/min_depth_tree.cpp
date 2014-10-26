#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
    if(root == 0) { 
        return 0;
    }
    if( root->left == 0 ) {
        //RIGHT Leaf if root->left == 0 //use case {1,2,#}
        return 1 + minDepth(root->right);
    }
    if( root->right == 0) {
        //LEFT Leaf
        return 1 + minDepth(root->left);
    }
    return 1+min (minDepth(root->left),minDepth(root->right));
}

int get_tri_min  (int a,int b,int c)  {
    int temp = min (a,b);
    return min (temp,c);
}

int minDepth1(TreeNode *root) {
    if(root == 0) { 
        return 0;
    } else {
        int root_depth = min (minDepth1(root->left),minDepth1(root->right));
        int left_dept = 1 + minDepth1 (root->left);
        int right_depth = 1 + minDepth1 (root->right);
        return ( get_tri_min (root_depth,left_dept,right_depth) + 1 );
    }
}


int main () {
    TreeNode *root = NULL;
    int min_depth = minDepth (root);
}
