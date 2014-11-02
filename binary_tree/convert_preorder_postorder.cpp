#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode  {
    struct TreeNode *left;
    struct TreeNode *right;
    int value;
    TreeNode (int x) : value(x),left (NULL),right(NULL) {}
};


//int inorder[] = {5,7,8,9,2,6};
//int postorder[] = {5,8,7,2,6,9};
TreeNode* build_tree_from_in_post_order1 (TreeNode *root,int post_order[],int in_order[]
        ,int start_pivot,int end_pivot,int post_order_index) {
    
    if (start_pivot <= end_pivot) {
        int data = post_order[post_order_index];
        int mid_index = -999;
        for (int i = start_pivot ;i <= end_pivot;i++) {
            if (in_order[i] == data) {
                mid_index = i;
                if (root == 0) {
                    root = new TreeNode(data);
                } 
                 //cout << "L<<<<<<<<<<<< start_pivot= " << start_pivot << " end_pivot(mid_index-1)= " << mid_index-1
                 //<<  "postindex = > " <<  mid_index-1<< " post_order[mid_index-1]-> "
                 //<< post_order[mid_index-1] << endl;
                 root->left = build_tree_from_in_post_order1(root->left,post_order,in_order
                         ,start_pivot,mid_index-1,mid_index-1) ;
                         //,start_pivot,mid_index-1,post_order_index-mid_index) ;
                 //cout << "R>>>>>>>>>>>> start_pivot(mid_index+1) = " << mid_index+1 << " end_pivot= " << end_pivot
                 //<<  "postindex = > " <<  post_order_index-1<< " post_order[post_order_index-1]-> "
                 //<< post_order[post_order_index-1] << endl;
            
                //Need to traverse backwards identify the condition (mid_index-1) : to increase the search space
                 //In case of matching the  inorder (9,2,6) and postorder (2,6,9)
                 root->right = build_tree_from_in_post_order1(root->right,post_order,in_order
                         ,mid_index-1,end_pivot,post_order_index-1);
                return root;
                //break;
            }
        }   
        //if (mid_index != -999) {
        //} 
    } else {
        return 0;
    }
}

TreeNode* build_tree_inorder_postorder_helper (vector<int> :: iterator inorder_start
        ,vector<int> :: iterator inorder_end
        ,vector<int> :: iterator postorder_start
        ,vector<int>:: iterator postorder_end ) {
    
    TreeNode *root = 0;
    if (inorder_start >= inorder_end) {
        return 0;
    } else {
        int next_root_val = *(postorder_end -1);
        vector<int> :: iterator root_index = find (inorder_start,inorder_end,next_root_val );
        size_t partition_size = root_index - inorder_start;
        root  = new TreeNode (next_root_val);
        root->left = build_tree_inorder_postorder_helper (inorder_start,root_index 
                ,postorder_start,postorder_start+partition_size);
        root->right = build_tree_inorder_postorder_helper (root_index+1
                ,inorder_end,postorder_start+partition_size,postorder_end-1);
    }
    return (root);
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    
    return (build_tree_inorder_postorder_helper (inorder.begin()
                ,inorder.end(),postorder.begin(),postorder.end()) );

}

int main () {

}
