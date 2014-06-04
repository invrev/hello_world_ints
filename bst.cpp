#include<iostream>
#include<stdlib.h>
using namespace std;

//NOTE :
//1.Preorder traversal (DLR) always visits node before its childern so it is DFS
//Best way to learn recursion


/*
 1.Traversal
 in case of linked list,prepend the data to the linked list.
 in case of tree,append the data in the tree.
*/

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
}tree_t,*ptree_t;


tree_t* create_node (int a_data) {
   tree_t *tmp_node = 0;
   tmp_node = (tree_t*) malloc(sizeof(tree_t));
   tmp_node->data = a_data;
   tmp_node->right = 0;
   tmp_node->left = 0;
   return (tmp_node);
}

void traverse_pre_order (tree_t *root) {
    if (root == 0){
        return;
    }
    cout << "data = " << (root->data) << endl;
    traverse_pre_order(root->left);
    traverse_pre_order(root->right);
}


void traverse_inorder (tree_t *root) {
   //base case
   if (root == 0) {
       //cout << "returns from null root" << endl;
       return;
   }
   traverse_inorder (root->left);
   cout << (root->data) << " ";
   traverse_inorder (root->right);
}

void traverse_postorder(tree_t *root) {
    //basecase
    if (root == 0) {
        return;
    }
    traverse_postorder(root->left);
    traverse_postorder(root->right);
    cout << "data = " << (root->data) << endl;
}

tree_t* create_bst(tree_t *node,int a_data) {
    if (node == 0) {
        //cout << "returning new node " << endl;
        cout << "       -N-     " << endl;
        return (create_node(a_data));
    }else {
        if (node->data > a_data) {
            //For successive left and right case ask base case to give next new pointer

            //cout << "asking for left node " << endl;
            cout << "       L--     " << endl;
            node->left = create_bst (node->left,a_data);
        }else {
            //cout << "asking for right node " << endl;
            cout << "       --R     " << endl;
            node->right = create_bst (node->right,a_data);
        }
        cout << "returning the node add = " << node << " and the data = " << node->data << endl;
        return node;
    }
}

//Search key from BST
void lookup (tree_t *root,int a_data) {
    if (root == 0) {
        cout << a_data << " not found in bst." << endl;
        return ;
    } else {
        if(root->data == a_data)  {
            cout << a_data << " found in bst." << endl;
            return ;
        }
        else if (root->data > a_data) {
            lookup (root->left,a_data); 
        }else 
        {
            lookup(root->right,a_data);
        }
    }
}

//Count number of nodes in BST
int count_no_nodes(tree_t *root) {
    if (root == 0) {
        return (0);
    }else {
        //D&C use divide = 2
        //conquer = add the elements
        //consider a tree with root,left and right
        int l_node_length = count_no_nodes(root->left) ;
        int r_node_length = count_no_nodes(root->right) ;
        return (l_node_length + r_node_length + 1);
        
        //return (count_no_nodes(root->left)+ 1 + count_no_nodes(root->right));
    }
}

//Print mirror image of the BST
void mirror_tree (tree_t *root) {
    if(root == 0) {
        return;
    } else {
      tree_t *tmp_node = root->left;  
      root->left = root->right;
      root->right = tmp_node;
      mirror_tree(root->left);
      mirror_tree(root->right);
    }
}

//
int total_cost_tree_sum(tree_t *root) {
    if (root == 0) {
        return 0;
    }else {
        int left_sum = total_cost_tree_sum(root->left);
        int right_sum = total_cost_tree_sum(root->right);
        return (left_sum + right_sum + root->data);
    }
}

void augment_left_tree (tree_t *root) {
   if (root == 0)  {
       return ;
   }else {
        augment_left_tree(root->left);
        //augment_left_tree(root->right);
        if (root->left == 0) {
         root->left = create_node(root->data);
        }else {
            tree_t *tmp_node = 0;
            tmp_node = create_node(root->data);
            tmp_node->left = root->left;
            root->left = tmp_node;
        }
   }

}
//Declared global
int path [100];

//traverse in DLR passion and store the root
void print_all_root_leaf_path(tree_t *root,int path_len) {
    if (root != 0) {
      path[path_len] = root->data;
      cout << "Inseritng data = "<< path[path_len] << "at location = " << path_len << "root_left = " <<  root->left << "and root_right = " << root->right  << endl;
      path_len = path_len + 1;
      //Added base case to print the path from root to leaf
      if (root->left == 0 && root->right == 0) {
            int i = 0;
            cout << "print r_L started " << endl;
            for (i=0;i<path_len;i++) {
                cout << path[i] << " ";
            }
      }
      //print_all_root_leaf_path(root->left,path,path_len);
      //print_all_root_leaf_path(root->right,path,path_len);
      print_all_root_leaf_path(root->left,path_len);
      print_all_root_leaf_path(root->right,path_len);
    }
}

int main () {
    tree_t *root = 0;
    cout << "size of tree_t = " << sizeof(tree_t) << endl;
    //int arr_[] = {12,2,34,4,6,90,-23};
    int arr_[] = {4,2,5,1,3};
    int i = 0;
    for (;i<5;i++) {
        root = create_bst (root,arr_[i]);
        cout << "after the data add root address =  " << root << " data = " << root->data << endl;
    }
    traverse_inorder(root);
    cout << endl;
    lookup (root,90);
    lookup (root,91);
    cout << "\nTotal # of nodes = " << count_no_nodes(root) << endl;
    //mirror_tree (root);
    int path_len = 0;
    cout << "Printing the all paths " << endl;
    //print_all_root_leaf_path(root,path,path_len);
    print_all_root_leaf_path(root,path_len);
    cout << "Completed printing the all paths " << endl;
    traverse_inorder(root);
    cout << endl;
    cout << "\n Total cost of the tree = " << total_cost_tree_sum (root) <<endl;
    augment_left_tree (root);

    traverse_inorder(root);
    cout << endl;
}
