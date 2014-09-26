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

void inorder_traversal (tree_node *node) {
    if (node != 0) {
      inorder_traversal (node->left);
      cout << node->data << " ";
      inorder_traversal (node->right);
    }
}

void bfs_traversal (tree_node *root) {
    queue<tree_node*> tree_queue;
    if (root) {
        tree_queue.push(root);
        while (!tree_queue.empty()) {
            tree_node *tmp_node = tree_queue.front();
            cout << tmp_node->data << " ";
            tree_queue.pop();
            if (tmp_node->left) {
                tree_queue.push(tmp_node->left);
            }
            if (tmp_node->right) {
                tree_queue.push(tmp_node->right);
            }
        }
    }
}


void zig_zag_traversal (tree_node *root) {
    stack<tree_node *>store_stack;
    stack<tree_node *>traverse_stack;
    cout << "bfs traversal " << endl;
    bool left_to_right = true;
    traverse_stack.push(root);
    while (root != 0) {
        while (!traverse_stack.empty()) {
            tree_node *tmp = traverse_stack.top();
            if (left_to_right) {
                if (tmp->left) 
                {
                    store_stack.push(tmp->left);
                } 
                if (tmp->right)
                {
                    store_stack.push(tmp->right);
                }
            } else {
                if (tmp->right) 
                {
                    store_stack.push(tmp->right);
                }
                if (tmp->left) 
                {
                    store_stack.push(tmp->left);
                } 
            }
          traverse_stack.pop();
          cout <<  tmp->data << " ";
        }
        if (store_stack.empty()) {
            root = 0;
        } else {
            cout << endl;
            left_to_right = !left_to_right;
            stack<tree_node *> tmp_stack = store_stack;
            store_stack = traverse_stack;
            traverse_stack= tmp_stack ;
        }
    }
    cout << endl;
}

int get_min (int data1,int data2) {
    if (data1 < data2) {
        return data1;
    } 
    return data2;
}

int get_max (int data1,int data2) {
    if (data1 > data2) {
        return data1;
    } 
    return data2;
}


tree_node* find_lca_from_bst (tree_node *root,tree_node* left,tree_node* right) {
    if (root) {
        if (get_min(left->data,right->data) <= root->data  
                && get_max(left->data,right->data) >= root->data) {
            return root;
        } else if (get_min (left->data,right->data) > root->data ) {
            return find_lca_from_bst (root->right,left,right);
        } else if (get_max (left->data,right->data) < root->data) {
            return find_lca_from_bst (root->left,left,right);
        }
    }
}


int compute_height_of_bst (tree_node *root) {
    if (root) {
        return ( get_max((1+compute_height_of_bst(root->left)),
                 (1+compute_height_of_bst(root->right))) );
    }

}

void postorder_iterative (tree_node *root) {
    vector<int> post_order_vec;
    if (root) {
        stack <tree_node*> postorder_stack;
        tree_node* tmp_node = root;
        tree_node *last_visited = 0;
        //while(tmp_node->right && tmp_node->right != last_visited) {
        //    postorder_stack.push(tmp_node->right);
        //    tmp_node = tmp_node->right;
        //}
        while (!postorder_stack.empty() || tmp_node != 0) {
            if (tmp_node) { 
                postorder_stack.push(tmp_node);
                tmp_node = tmp_node->left;
            } else {
                tree_node* current_node = postorder_stack.top();   
                //To avoid revisting the same node use the last_visited AS it is L->R->D
                if (current_node->right && current_node->right != last_visited) {
                    tmp_node = current_node->right;
                } else {
                    postorder_stack.pop();   
                    //visit_node 
                    post_order_vec.push_back(current_node->data);
                    last_visited = current_node;
                }
            }
        }
    }
    int len = post_order_vec.size();
    cout << "the len = " << len << endl;
    for(int i=0;i<len;i++) {
        cout << post_order_vec[i] << " ";
    }
    cout << endl;
}


void postorder_iterative_1 (tree_node *root) {
    vector<int> post_order_vec;
    if (root) {
        stack <tree_node*> postorder_stack;
        //postorder_stack.push (root);
        tree_node* tmp_node = root;
        tree_node *last_visited = 0;
        while (!postorder_stack.empty() || tmp_node != 0) {
            //tmp_node = postorder_stack.top();
            while (tmp_node) {
                postorder_stack.push(tmp_node);
                tmp_node = tmp_node->left;
            }
            tree_node* current_node = postorder_stack.top();   
            if (current_node->right && current_node->right != last_visited) {
                //postorder_stack.push(tmp_node->right);
                tmp_node = current_node->right;
            } else {
                //tmp_node = postorder_stack.top();   
                last_visited = current_node ;
                post_order_vec.push_back(current_node->data);
                postorder_stack.pop();
            }
        }
    }

    for (int i=0;i<post_order_vec.size();i++) {
        cout << post_order_vec[i] << " ";
    }
    cout << endl;
}


vector<int> dfs_bfs_vector;
void do_bfs_in_dfs_manner (tree_node *root) {
    if (root) {
        dfs_bfs_vector.push_back(root->data);
        do_bfs_in_dfs_manner (root->left);
        do_bfs_in_dfs_manner (root->right);
    }
}


int main () {
    int input_arr[]  = {20,12,3,14,39,28,40,41,45,47,49};
    tree_node *root = 0; 
    for (int i=0;i<11;i++) {
        root = create_bst (input_arr[i],root);
    }

    do_bfs_in_dfs_manner (root);
    int len = dfs_bfs_vector.size();
    for (int i=0;i<len;i++) {
        cout << dfs_bfs_vector[i] << " ";
    }
    cout << endl;
    inorder_traversal(root);
    cout << endl;
    bfs_traversal (root);
    cout << endl;
    zig_zag_traversal (root);
    tree_node * lca_node = find_lca_from_bst (root,root->left->left,root->left->right) ;
    cout << "the lca of the node = " << lca_node->data << endl;

    int height = compute_height_of_bst (root);
    cout << "balanced height " << height << endl;
    postorder_iterative (root);
    postorder_iterative_1 (root);
}
