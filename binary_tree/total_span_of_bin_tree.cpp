#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<map>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Find the span of the tree
void find_total_span_of_bin_tree (TreeNode* root,int span_cnt,int* min,int* max) {
    if (root != 0) {
        *max = max (*max,(span_cnt-1));
        *min = min (*min,(span_cnt-1));
        find_total_span_of_bin_tree(root->left,(span_cnt-1),min,max);
        *max = max (*max,(span_cnt+1));
        *min = min (*min,(span_cnt+1));
        find_total_span_of_bin_tree(root->right,(span_cnt+1),min,max);
    }
}


int main () {

    int max = INT_MIN;
    int min = INT_MAX;
    find_total_span_of_bin_tree (root,span_cnt,&min,&max);
}
