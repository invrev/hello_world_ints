#include<iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p && q) {
        return ( p->val == q->val && (isSameTree (p->left,q->left))
                    && (isSameTree (p->right,q->right)) );
    }else if (p != 0 || q != 0) {
        return false;
    }
}

int main () {
}