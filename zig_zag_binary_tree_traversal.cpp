#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;

typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
}tree_node;

tree_node* create_node (int data) {
    tree_node* node = (tree_node*) malloc(sizeof(struct tree_node));
    node->data = data;
    node->left = 0;
    node->right = 0;
    return (node);
}

tree_node* create_bst (int data,tree_node *node) {
    if (node == 0) {
        node = create_node (data);
    } else if (node->data > data) {
        node->left =  create_bst(data,node->left) ;
    } else if (node->data < data) {
        node->right = create_bst (data,node->right);
    }
    return node;
}

void zig_zag_traversal (tree_node *root) {
    stack<tree_node *>store_stack;
    stack<tree_node *>traverse_stack;
    cout << "bfs traversal " << endl;
    bool left_to_right = true;
    traverse_stack.push(root);
    while (root != 0) {
        while (!traverse_stack.empty()) {
            tree_node *current_node = traverse_stack.top();
            if (left_to_right) {
                if (current_node->left) 
                {
                    store_stack.push(current_node->left);
                } 
                if (current_node->right)
                {
                    store_stack.push(current_node->right);
                }
            } else {
                if (current_node->right) 
                {
                    store_stack.push(current_node->right);
                }
                if (current_node->left) 
                {
                    store_stack.push(current_node->left);
                } 
            }
          traverse_stack.pop();
          cout <<  current_node->data << " ";
        }
        if (store_stack.empty()) {
            root = 0;
        } else {
            cout << endl;
            left_to_right = !left_to_right;
            //Swap the stack
            stack<tree_node *> tmp_stack = store_stack;
            store_stack = traverse_stack;
            traverse_stack= tmp_stack ;
        }
    }
    cout << endl;
}


int main () {
    int input_arr[]  = {20,12,3,14,39,28,40,41,45,47,49};
    tree_node *root = 0; 
    for (int i=0;i<11;i++) {
        root = create_bst (input_arr[i],root);
    }
    cout << endl;
    zig_zag_traversal (root);
}
