#include<iostream>
using namespace std;

struct TreeNode  {
    int val;
    TreeNode *left;
    TreeNode *right;

};

//I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1), and the right subtree will contain elements (i+1) to n. I use recursive calls to get back all possible trees for left and right subtrees and combine them in all possible ways with the root.

vector<TreeNode*> generateTreesRec(int start, int end){
        vector<TreeNode*> v;
        if(start > end){
            //for the case 
            //Input : 0
            //Output:	[]
            //Expected: [{}]
            v.push_back(NULL);
            return v;
        }
        for(int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTreesRec(start, i - 1);
            vector<TreeNode*> right = generateTreesRec(i + 1, end);
            TreeNode *node;
            for(int j = 0; j < left.size(); ++j){
                for(int k = 0; k < right.size(); ++k){
                    //create tree node 
                    node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    //add to vector
                    v.push_back(node);
                }
            }
        }
        return v;
}

vector<TreeNode *> generateTrees(int n) {
    return generateTreesRec(1, n);
}



int main () {

}
