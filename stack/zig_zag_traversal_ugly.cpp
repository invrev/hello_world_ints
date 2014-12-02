#include<iostream>
#include<vector>
using namespace std;

struct NodeWithLevel  {
        TreeNode *root_node;
        int level;
        NodeWithLevel (TreeNode *root,int level) : root_node (root),level (level) {};
    } ; 
    


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector < vector <int> > zig_zag_vec;
    stack<NodeWithLevel *>store_stack;
    stack<NodeWithLevel *>traverse_stack;
    bool left_to_right = true;
    int level = 1;
    if (root == 0) {
        return zig_zag_vec;
    }
    traverse_stack.push(new NodeWithLevel(root,level) );
    
    zig_zag_vec.resize(1);
    
    while (root != 0) {
        while (!traverse_stack.empty()) {
            NodeWithLevel *nodeWithLevel = traverse_stack.top();
            TreeNode *current_node = nodeWithLevel->root_node;
            level = nodeWithLevel->level;
            zig_zag_vec[level - 1].push_back(current_node->val);
            if (current_node->left || current_node->right) {
                level += 1;
                zig_zag_vec.resize(level);
            }
            if (left_to_right) {
                if (current_node->left) 
                {
                    store_stack.push(new NodeWithLevel(current_node->left,level+1));
                } 
                if (current_node->right)
                {
                    store_stack.push(new NodeWithLevel(current_node->right,level+1));
                }
            } else {
                if (current_node->right) 
                {
                    store_stack.push(new NodeWithLevel(current_node->right,level+1));
                }
                if (current_node->left) 
                {
                    store_stack.push(new NodeWithLevel(current_node->left,level+1));
                } 
            }
          traverse_stack.pop();
        }
        if (store_stack.empty()) {
            root = 0;
        } else {
            //cout << endl;
            left_to_right = !left_to_right;
            //Swap the stack
            stack<NodeWithLevel *> tmp_stack = store_stack;
            store_stack = traverse_stack;
            traverse_stack= tmp_stack ;
        }
    }
    return zig_zag_vec;
    }
