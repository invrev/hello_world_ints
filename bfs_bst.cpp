#include<iostream>
#include<stdlib.h>
using namespace std;

//BFS tarversal of the BST

typedef struct bt {
    int data;
    struct bt *left;
    struct bt *right;
} bt_ptr;


bt_ptr* create_node (int data) {
    bt_ptr *bt_node = (bt_ptr*) malloc(sizeof(bt_ptr));
    bt_node->data = data;
    bt_node->left = 0;
    bt_node->right = 0;
    return (bt_node);
}

bt_ptr* create_bst (bt_ptr *root,int data) {
    if (root == 0) {
        root =  create_node (data);
        return (root);
    } else if ( data < root->data) {
      root->left = create_bst(root->left,data);
    } else {
      root->right = create_bst(root->right,data);
    }
}

void traverse_bst (bt_ptr *root) {
    if (root != 0) {
        traverse_bst(root->left);
        cout << root->data << " ";
        traverse_bst(root->right);
    }
}


void traverse_and_tweak (bt_ptr *root) {
    if (root != 0) {
     traverse_and_tweak (root->left);
    }
}


struct bt_ptr_q_struct {
    bt_ptr* que[10];
    int push_index ;
    int pop_index;
};

typedef bt_ptr_q_struct  bt_ptr_q;

void init_q (bt_ptr_q *q) {
    //for (int i=0;i<10;i++) {
    //    q->que[i] = (bt_ptr*) malloc( sizeof(bt_ptr) ); 
    //}
    q->push_index = 0;
    q->pop_index = 0;
}
int is_q_empty (bt_ptr_q *q) {
   
   int push_index = q->push_index;
   int pop_index =  q->pop_index;
   if (push_index - pop_index <= 0 ) {
        return 1; 
   }
   return 0;
}

void add_ele_in_q (bt_ptr_q *q,bt_ptr *root) {
    if (root != 0)  {
        q->que[q->push_index] = root;
        q->push_index += 1;
    }
}

bt_ptr * remove_ele_from_q (bt_ptr_q *q) {
    bt_ptr *temp =  q->que[q->pop_index];
    q->pop_index += 1;
    return (temp);

}
void traverse_level_order (bt_ptr *root,bt_ptr_q *q){
    init_q (q);
    add_ele_in_q (q,root);
    while ( !is_q_empty(q) ) {
        bt_ptr *node = remove_ele_from_q (q);  
        cout << node->data << " ";
        add_ele_in_q (q,node->left);
        add_ele_in_q (q,node->right);
    }

}


int main () {
    int arr_[] = {5,3,1,2,10,15,8,7,9,16};
    bt_ptr *root_node = 0;
    for (int i=0;i<10;i++) {
        //cout << arr_[i] << " " ;
        root_node = create_bst(root_node,arr_[i]); 
    }
    traverse_bst(root_node);
    cout << endl;
    bt_ptr_q *q;
    traverse_level_order (root_node,q);
    cout << endl;

}
