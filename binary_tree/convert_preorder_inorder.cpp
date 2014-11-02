#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL)
                      , right(NULL) {}
};

//If mid == 0 then we traversed the both array and now pointer is @the same inoder and preorder
//5,7,8,9,2,6 : inorder
//9,7,5,8,6,2 : preorder
/*
*inorder : where is the position
*preorder : which is the element
*
*   (5,7,8) <<<<9>>> (2,6)
*   (5) <<<<7>>> (8)        (2)
*   (5)                     (6)
*   (8)
*
    root = build_tree_from_in_pre_order (root,preorder,inorder,6,4);
*
*/
TreeNode* build_tree_from_in_pre_order (TreeNode *root,int pre_order[]
        ,int in_order[],int inorder_len,int mid) {

    if (inorder_len <= 0 || mid < 0) {
        return 0;
    } else {
        int next_root_data = pre_order[0];
        for (int i=0;i<inorder_len;i++) {
            if (next_root_data == in_order[i]) {
                mid = i;
                if (root == 0) {
                    root = new TreeNode(next_root_data);
                }
                root->left = build_tree_from_in_pre_order (root->left,pre_order+1,in_order
                                                            ,inorder_len-(mid),mid-1);
                root->right = build_tree_from_in_pre_order (root->right,pre_order+(mid+1)
                                                            ,in_order+mid+1,inorder_len-(mid+1),mid+1);
                return root;
            }
        }
    }
}


TreeNode* build_tree_from_in_pre_order_helper (vector<int> :: iterator pre_order_start
        ,vector<int> :: iterator pre_order_end
        ,vector<int> :: iterator in_order_start
        ,vector<int> :: iterator in_order_end ) {
    
    TreeNode *root = 0;

    if (pre_order_start >= pre_order_end) {
        return 0;
    } else {
        //1.get the start element from preorder
        //2.Find index position in the inorder (root_index)
        //3.Parition/divide the preorder between <inorder_start,(1 + (root_index - inorder_start) ) > and < (1 + (root_index - inorder_start) ),inorder_end>
        int next_root_data = *pre_order_start ;
        vector <int>::iterator root_index = find(in_order_start,in_order_end,next_root_data);
        vector <int>::size_type partition_size = root_index - in_order_start;
        root = new TreeNode(next_root_data);
        root->left = build_tree_from_in_pre_order_helper (
                 pre_order_start+1
                ,pre_order_start+1+partition_size
                ,in_order_start,root_index);
        root->right = build_tree_from_in_pre_order_helper (
                pre_order_start+1+partition_size
                ,pre_order_end
                ,root_index+1,in_order_end);

    }
    return root;
}



TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode *root = NULL;
    int len = preorder.size();
    TreeNode *newRoot = build_tree_from_in_pre_order_helper (preorder.begin()
            ,preorder.end(),inorder.begin(),inorder.end());

    return newRoot ;
}

int main () {

}
