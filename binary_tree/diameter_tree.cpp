#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
  http://www.cs.duke.edu/~ola/courses/cps100spr96/tree/trees.html
  The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. 
The diagram below shows two trees each with diameter nine
, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
In particular, note that the diameter of a tree T is the largest of the following quantities:
the diameter of T's left subtree
the diameter of T's right subtree
the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
You are to write a function TreeDiameter that returns the diameter of a binary tree. In writing TreeDiameter you may call the function TreeHeight and Max discussed above.
  int TreeDiameter(Tnode *t)
  // postcondition: returns diameter of tree with root t
For full credit you should visit nodes in the tree the minimal number of times possible, in particular the complexity of your code should be O(n). This may entail writing an auxiliary function called from TreeDiameter. In particular, you may need to write a function that uses a reference parameters to pass back the height. I used a function whose prototype is given below:
void DoDiameter(Tnode * t, int & height, int & diameter)
// postcondition: sets height to height of tree t, 
//                sets diameter to diameter of t
General tree
A tree in which each node can have an arbitray number of children, and in which each node stores an integer, can be implemented using the following declarations:
        struct GTnode 
        {
            int info;
            GTnode * child;       // first child of node
            GTnode * sibling;     // sibling of node
            GTnode(int val, GTnode * kid = 0, GTnode * sib = 0)
                : info(val),
                  child(kid),
                  sibling(sib)
            {}
        };
**/

//In particular, note that the diameter of a tree T is the largest of the following quantities:
//1.The diameter of T's left subtree
//2.The diameter of T's right subtree
//3.The longest path between leaves that goes 
//through the root of T (this can be computed from the heights of the subtrees of T)
int get_tri_max (int a,int b,int c) {
    int temp = max (a,b);
    return max (temp,c);
}

//compute the height of the tree
int depth_of_tree (TreeNode* root) {
    if (root == 0) {
        return 0;
    }else {
        return 1 +  max(depth_of_tree (root->left) ,depth_of_tree (root->right));
    }
}

//Find the diameter of the tree
int tree_diameter (TreeNode* root) {
    if (root == 0) {
        return 0;
    } else {
        //get_max (tree_diameter(root->left),tree_diameter(root->right),tree_diameter(root));
        int root_depth = max (depth_of_tree (root->left),depth_of_tree (root->right));
        int left_dept = 1 + tree_diameter (root->left);
        int right_depth = 1 + tree_diameter (root->right);
        return ( get_tri_max (root_depth,left_dept,right_depth) + 1 );
    }
}

int main () {

    TreeNode* root = NULL;
    int depth = tree_diameter(root);
}

