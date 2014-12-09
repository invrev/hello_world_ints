#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int aval) : 
        val(aval),left(NULL),right(NULL) 
    {

    };
};

struct TreeNodeP {
    int val;
    TreeNodeP *left;
    TreeNodeP *right;
    TreeNodeP *parent;
    TreeNodeP(int aval) : 
        val (aval),left(NULL),right(NULL),parent(NULL) 
    {

    };
};

//struct for the interval tree
struct iTreeNode {
    int start;
    int end;
    int maxVal;
    iTreeNode *left;
    iTreeNode *right;
    iTreeNode (int aStart,int aEnd) : 
        start(aStart),end(aEnd),left(NULL),right(NULL) 
    {

    };
};

//visualize
struct graphNode {
    int outDeg;
    int label;
    vector<graphNode *> edges;
    graphNode (int aLabel,int aOutDeg) : 
        label(aLabel),outDeg(aOutDeg),edges(aOutDeg)
    {
    };
};



bool sameTree (TreeNode *p,TreeNode *q) {
    if (!p && !q) {
        return true;
    } else if ( (!p && q ) || (p && !q) ) {
        return false;
    } else {
        if (p->val == q->val) {
            return  ( sameTree (p->left,q->left) && sameTree (p->right,q->right) ) ;
        } 
        return false;
    }
}


bool isSymmetricHelper(TreeNode *p,TreeNode *q) {
    if (!p && !q) {
        return true;
    } else if ( (!p && q ) || (p && !q) ) {
        return false;
    } else {
        if (p->val == q->val) {
            return  ( isSymmetricHelper(p->left,q->right) && isSymmetricHelper(p->right,q->left) ) ;
        } 
        return false;
    }
}

//check wheather is tree is mirror immage
bool isSymmetric(TreeNode *root) {
    if (!root || (!root->left && !root->right) ) {
        return true;
    } else if (root->left && root->right) {
        isSymmetricHelper (root->left,root->right);
    } else {
        return false;
    }
}


int minBST (TreeNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->val;
}
int maxBST (TreeNode *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->val;
}
bool isValidBST (TreeNode *root) {
    if (!root) {
        return true;
    } else {
        if (root->right != NULL && root->val >= minBST(root->right) )  {
            return false;
        }
        if ( root->left != NULL && root->val <= maxBST(root->left) ) {
            return false;
        }
        //Perform non-tail recursion
        if ( !isValidBST (root->left) || !isValidBST(root->right) ) {
            return false;
        }
        //all cases covered
        return true;
    }
}


TreeNode* find_lca (TreeNode *root,TreeNode *left_ip,TreeNode *right_ip) {
   if (!root)  {
       return NULL;
   }
   else if (root == left_ip || root == right_ip) {
        //cout << root->val << endl;
        return root;
    }
   //Traverse with non-tail recursion
    TreeNode *l = find_lca (root->left,left_ip,right_ip);
    //if (l) {
    //    cout << "left "  << l->val << endl;
    //}
    
    TreeNode *r = find_lca (root->right,left_ip,right_ip);
    //if (r) {
    //    cout << "right"  << r->val << endl;
    //}
    //Comparison of nodes at the same level
    if (l && r) {
        //cout << "r = "  << root->val << endl;
        return root;
    }
    //check the nodes at different level
    if (l) {
        return l;
    } else {
        return r;
    }
}

int compute_depth(TreeNodeP *node) {
    int depth = 0;
    while (node) {
        node = node->parent;
    }
    return depth;

}

//Idea with parent pointer is make the both nodes of same length and traverse the parent
TreeNodeP* find_lca (TreeNodeP* root,TreeNodeP *left_ip,TreeNodeP *right_ip) {
    if (!root) {
        return 0;
    } else {
        //compute the depth
        int depths = compute_depth(left_ip);
        int depthl = compute_depth(right_ip);
        if (depths > depthl) {
            //Note left_ip always of small height while right_ip is of large height
            swap (left_ip,right_ip);
        }
        int offset = max(depths,depthl) - min(depths,depthl);
        for (int i=0;i<offset;i++) {
            right_ip = right_ip->parent;
        }
        while (left_ip) {
            if (left_ip == right_ip) {
                return left_ip;
            }
            left_ip = left_ip->parent;
            right_ip = right_ip->parent;
        }
    }
    return NULL;
}

int find_max_height(TreeNode *root) {
    queue <TreeNode*> t_queue;
    int max_height = 0;
    int nodes_to_visit = 0;
    int curr_visited = 1;
    if (root) {
        t_queue.push(root);
        while (!t_queue.empty()) {
            TreeNode *tmp = t_queue.front();
            if (tmp->left) {
                t_queue.push(tmp->left);
                nodes_to_visit += 1;
            }
            if (tmp->right) {
                t_queue.push(tmp->right);
                nodes_to_visit += 1;
            } 
            t_queue.pop();
            curr_visited--;
            if (curr_visited == 0) {
                //STAY till end
                max_height += 1;
                curr_visited = nodes_to_visit;
                nodes_to_visit = 0;
            }
        }
    }
    return max_height;
    //cout << endl;
}

int find_min_height (TreeNode *root) {
    queue <TreeNode*> t_queue;
    int min_height = 0;
    int nodes_to_visit = 0;
    int curr_visited = 1;
    if (root) {
        t_queue.push(root);
        while (!t_queue.empty()) {
            TreeNode *tmp = t_queue.front();
            if (tmp->left) {
                t_queue.push(tmp->left);
                nodes_to_visit += 1;
            }
            if (tmp->right) {
                t_queue.push(tmp->right);
                nodes_to_visit += 1;
            } 
            t_queue.pop();
            if (tmp->left == 0 && tmp->right ==0) {
                min_height += 1;
                return min_height;
            }
            curr_visited--;
            if (curr_visited == 0) {
                min_height += 1;
                curr_visited = nodes_to_visit;
                nodes_to_visit = 0;
            }
        }
    }
    return min_height ;
}


//Finding the kth larget element by reverse inorder traversal
void find_kth_largest_from_bst (TreeNode *root,int& k) {
    if (!root) {
        return;
    }
    find_kth_largest_from_bst (root->right,k);
    k--;
    if (k == 0) {
        cout << "the kth largest " << root->val << endl;
        return;
    }
    find_kth_largest_from_bst (root->left,k);
}







int main () {
   //         15
   //     5          30
   //  3      7   20      35
   //6

    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(20);
    root->right->right = new TreeNode(35);
    //bottom_up_travesal (root);
    find_max_height (root);
    //find_lca (root,root->left->right,root->left->right->left);
    find_lca (root,root->left->right,root->right->left);
    int k = 2;
    find_kth_largest_from_bst  (root,k);

    graphNode *g = new graphNode(1,3);
    g->edges[0] = new graphNode(2,2);
    g->edges[1] = new graphNode(3,3);
    g->edges[2] = new graphNode(4,2);
    g->edges[3] = new graphNode(5,3);

}
