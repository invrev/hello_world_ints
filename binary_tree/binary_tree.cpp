#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<map>
#include<vector>
using namespace std;

struct tree_node  {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};
typedef tree_node bt_node;

//utility to create the node
tree_node* create_node (int data) {
    bt_node *tree_node = (bt_node *) malloc(sizeof(bt_node));
    tree_node->data = data;
    tree_node->left = 0;
    tree_node->right = 0;
    return (tree_node);
}
void print_array  (int arr[],int len) {
    for (int i=0;i<len;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print_list (vector<int>& vec_lst) {
    int len = vec_lst.size();
    for (int i=0;i<len;i++) {
        cout << vec_lst [i] << " ";
    }
    cout << endl;
}
void get_all_k_v_from_vertical_sum (map <int,int> vertical_sum_map) {
    map<int,int> :: iterator start_it = vertical_sum_map.begin();
    map<int,int> :: iterator end_it = vertical_sum_map.end();
    for ( start_it ;start_it != end_it ;start_it++ ) {
        int key = start_it->first;
        int value = start_it->second;
        cout << "(level = " << key << ", value = " << value << ")";
    }
    cout << endl;
}
bt_node* append_node_to_tree (bt_node *root,int no,int index) {
    if (root == 0) {
        root = create_node (no);
    } else if (index % 2 == 0) {
        root->left = append_node_to_tree (root->left,no,index);
    } else {
        root->right = append_node_to_tree (root->right,no,index);
    }
    return (root);
}
void traverse_tree_inorder (bt_node* root) {
    if (root != 0) {
        traverse_tree_inorder (root->left);
        cout << root->data << " ";
        traverse_tree_inorder (root->right);
    }
}
void traverse_tree_preorder (bt_node* root) {
    if (root != 0) {
        cout << root->data << " ";
        traverse_tree_preorder (root->left);
        traverse_tree_preorder (root->right);
    }
}
void traverse_tree_postorder (bt_node* root) {
    if (root != 0) {
        traverse_tree_postorder (root->left);
        traverse_tree_postorder (root->right);
        cout << root->data << " ";
    }
}
//Given preorder and indorder create the binary tree and verify the result
bt_node * append_node_to_tree_with_pos (bt_node *root,int data,int pos) {
    //pos = 1 : left
    //pos = 2 : right
    if (root == 0) {
        root = create_node (data);
    }else if (pos == 1) {
        root->left = append_node_to_tree_with_pos (root->left,data,pos);
    } else if (pos == 2){
        root->right = append_node_to_tree_with_pos (root->right,data,pos);
    }
    return (root);
}

void get_mid_elements (int preorder_arr[],int inorder_arr[],int len) {
    int mid = 0;
    int next_mid = 0;
    bt_node *root = 0;
    for (int i=0;i<len;i++) {
        int next_root = preorder_arr[i];
        for (int j=0;j<len;j++)   {
            if (inorder_arr[j] == next_root) {
                next_mid = j;
                break;
            }
        }
        cout << "mid_ele = " << next_root << " mid_pos = "<< mid << endl;
        if (next_mid > mid) {
            //go right
            root = append_node_to_tree_with_pos (root,next_root,2);
        } else {
            //go left
            //Need some kind of info that tells what was last node
            root = append_node_to_tree_with_pos (root,next_root,1);
        }
        mid = next_mid;
    }
    traverse_tree_inorder (root);
    cout << endl;
    traverse_tree_preorder (root);
}

//If mid == 0 then we traversed the both array and now pointer is @the same inoder and preorder
//5,7,8,9,2,6 : inorder
//9,7,5,8,6,2 : preorder
/*
*inorder : where is the position
*preorder : which is the element
*
*   (5,7,8) <<<<9>>> (2,6)
*   (5) <<<<7>>> (8)        (2)
*   (5)                     (6)
*   (8)
*
*
*/
bt_node* build_tree_from_in_pre_order (bt_node *root,int pre_order[]
        ,int in_order[],int inorder_len,int mid) {
    if (inorder_len <= 0 || mid < 0) {
        return 0;
    } else {
        int next_root_data = pre_order[0];
        for (int i=0;i<inorder_len;i++) {
            if (next_root_data == in_order[i]) {
                mid = i;
                if (root == 0) {
                    root = create_node (next_root_data);
                }
                root->left = build_tree_from_in_pre_order (root->left,pre_order+1,in_order
                                                            ,inorder_len-(mid),mid-1);
                root->right = build_tree_from_in_pre_order (root->right,pre_order+(mid+1)
                                                            ,in_order+mid+1,inorder_len-(mid+1),mid+1);
                return root;
            }
        }
    }
}
//NOTE : mid => to determine the inorder_mid
//inoder start and end 
bt_node* build_tree_from_in_post_order (bt_node *root,int post_order[]
        ,int in_order[],int inorder_end,int inorder_mid,int len,string dir) {
    if (inorder_end < 0 || inorder_mid < 0) {
        return 0;
    } else {
        int next_root_data = post_order[len-1];
        cout << "next_root_data = " << next_root_data << "|inorder_end =" << inorder_end ;
        cout << "|in_order_dir = " << dir  << "inorder [0] = " << in_order[0] << endl;
        inorder_mid  = -999;
        if (next_root_data == in_order[0]) {
            inorder_mid  = 0;
        }
        for (int i=0;i<inorder_end;i++) {
            if (next_root_data == in_order[i]) {
                inorder_mid = i;
                break;
            }
        }
        if (inorder_mid  != -999) {
                cout << "inorder_mid = " << inorder_mid  << endl;
                if (root == 0) {
                    root = create_node (next_root_data);
                }
                int post_order_len = len-inorder_mid;
                //cout <<  "in_order mid = " << inorder_mid << endl;
                //cout <<  "in_order left start = " << in_order[inorder_mid-1] << endl;
                root->left = build_tree_from_in_post_order (root->left,post_order,in_order
                                                            //,inorder_end-(inorder_mid)
                                                            ,(inorder_mid)
                                                            ,inorder_mid-1,post_order_len,"left");
                post_order_len = len - 1;
                //cout <<  "in_order mid = " << inorder_mid << endl;
                //cout <<  "in_order right start = " << in_order[inorder_mid+1] << endl;
                root->right = build_tree_from_in_post_order (root->right,post_order + (inorder_mid)
                                                            ,in_order+(inorder_mid+1)
                                                            ,inorder_end-(inorder_mid+1)
                                                            ,inorder_mid+1
                                                            //,post_order_len  
                                                            ,inorder_end-(inorder_mid+1) 
                                                            ,"right");
                return root;
        }
    }
}
bt_node * build_tree_from_in_post_order1 (bt_node *root,int post_order[],int in_order[]
        ,int start_pivot,int end_pivot,int post_order_index) {
    if (start_pivot <= end_pivot) {
        int data = post_order[post_order_index];
        int mid_index = -999;
        for (int i = start_pivot ;i <= end_pivot;i++) {
            if (in_order[i] == data) {
                mid_index = i;
                if (root == 0) {
                    root = create_node(data);
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
void test_inorder_postorder () {
    int inorder[] = {5,7,8,9,2,6};
    int postorder[] = {5,8,7,2,6,9};
    bt_node *root = 0;
    //mid can be any non -ve and non-zero element
    //root = build_tree_from_in_post_order (root,postorder,inorder,6,1,6,"left");
    root = build_tree_from_in_post_order1 (root,postorder,inorder,0,5,5);
    cout << "inorder : " ;
    traverse_tree_inorder (root);
    cout << endl;
    cout << "preorder : " ;
    traverse_tree_preorder(root);
    cout << endl;
    cout << "postorder : " ;
    traverse_tree_postorder(root);
    cout << endl;
}
bt_node* create_bin_tree (int arr[],int len) {
    bt_node *root = 0;
    for (int i=0;i<len;i++) {
        root = append_node_to_tree (root,arr[i],i);
    }
    return (root);
}
//Find the vertical sum in the tree
//As we cannot use the -ve array indexing one hack is 
//to use the 2 array 1 for the -ve and the other for the +ve
void get_vertical_sum (bt_node *root,int dist,int pos_arr[],int neg_arr[]) {
    //Assign the distance to each node
    if (root != 0) {
        cout << "root = " << root->data <<  " dist = " << dist << endl;
        if (dist < 0) {
            neg_arr[-dist] = pos_arr[-dist] + root->data;
        } else {
            pos_arr[dist] = pos_arr[dist] + root->data;
        }
        get_vertical_sum (root->left,dist+(-1),pos_arr,neg_arr);
        get_vertical_sum (root->right,dist+(1),pos_arr,neg_arr);
    }
}
//The concept of horizontal distance computed by assigning -1 to left subtree and 1 to right subtree
void get_vertical_sum_v2 (bt_node *root,int dist,map<int,int>& vertical_sum_map) {
    //Assign the distance to each node
    if (root != 0) {
        if (vertical_sum_map.find(dist) == vertical_sum_map.end() ) {
            vertical_sum_map[dist] = root->data;
        } else {
            //cout << "root = " << root->data <<  " dist = " << dist << endl;
            int prev_sum = vertical_sum_map[dist];
            prev_sum += root->data;
            vertical_sum_map[dist] = prev_sum;
        }
        get_vertical_sum_v2 (root->left,dist+(-1),vertical_sum_map);
        get_vertical_sum_v2 (root->right,dist+(1),vertical_sum_map);
    }
}
//Compute the sum from root to leaf
void print_sum_from_root_to_leaf (bt_node *root,int sum,vector<int>& tree_list_vector) {
    if (root != 0) {
        if (root->left == 0 && root->right == 0)  {
            tree_list_vector.push_back(root->data);
            //TO test uniquely identify the sequence
            tree_list_vector.push_back(-1);
            cout << "the sum " << sum+root->data << endl;
        } else {
            tree_list_vector.push_back(root->data);
            print_sum_from_root_to_leaf (root->left, (sum+root->data),tree_list_vector);
            print_sum_from_root_to_leaf (root->right, (sum+root->data),tree_list_vector);
        }
    }
}
//Find the LCA
//convert BST to DLL
void find_lca_of_bt () {
}
int get_max (int a,int b) {
    if (a > b) {
        return a;
    } 
    return b;
}
int get_min (int a,int b) {
    if (a < b) {
        return a;
    } return b;
}
//Find the span of the tree
void find_total_span_of_bin_tree (bt_node *root,int span_cnt,int* min,int* max) {
    if (root != 0) {
        *max = get_max (*max,(span_cnt-1));
        *min = get_min (*min,(span_cnt-1));
        find_total_span_of_bin_tree(root->left,(span_cnt-1),min,max);
        *max = get_max (*max,(span_cnt+1));
        *min = get_min (*min,(span_cnt+1));
        find_total_span_of_bin_tree(root->right,(span_cnt+1),min,max);
    }
}

//compute the height of the tree
int depth_of_tree (bt_node *root) {
    if (root == 0) {
        return 0;
    }else {
        return 1 +  get_max(depth_of_tree (root->left) ,depth_of_tree (root->right));
    }
}

//In particular, note that the diameter of a tree T is the largest of the following quantities:
//1.The diameter of T's left subtree
//2.The diameter of T's right subtree
//3.The longest path between leaves that goes 
//through the root of T (this can be computed from the heights of the subtrees of T)
int get_tri_max (int a,int b,int c) {
    int temp = get_max (a,b);
    return get_max (temp,c);
}
/**
  http://www.cs.duke.edu/~ola/courses/cps100spr96/tree/trees.html
  The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
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

//Find the diameter of the tree
int tree_diameter (bt_node *root) {
    if (root == 0) {
        return 0;
    } else {
        //get_max (tree_diameter(root->left),tree_diameter(root->right),tree_diameter(root));
        int root_depth = get_max (depth_of_tree (root->left),depth_of_tree (root->right));
        int left_dept = 1 + tree_diameter (root->left);
        int right_depth = 1 + tree_diameter (root->right);
        return ( get_tri_max (root_depth,left_dept,right_depth) + 1 );
    }
}

void test_inorder_preorder () {
    int inorder[] = {5,7,8,9,2,6};
    int preorder[] = {9,7,5,8,6,2};
    //int inorder[] = {4,2,5,1,3,6};
    //int preorder[] = {1,2,4,5,3,6};
    //Postorder traversal is {4, 5, 2, 6, 3, 1}
    //int postorder[] = {5,8,7,2,6,9};
    bt_node *root = 0;
    //mid can be any non -ve and non-zero element
    root = build_tree_from_in_pre_order (root,preorder,inorder,6,4);
    cout << "inorder : " ;
    traverse_tree_inorder (root);
    cout << endl;
    cout << "postorder : " ;
    traverse_tree_postorder (root);
    cout << endl;
    cout << "preorder : " ;
    traverse_tree_preorder(root);
    cout << endl;
    int span_cnt = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    find_total_span_of_bin_tree (root,span_cnt,&min,&max);
    cout << min << "," << max << endl;
    //int pos_arr[] = {0,0,0,0,0,0,0,0};
    //int neg_arr[] = {0,0,0,0,0,0,0,0};
    //get_vertical_sum (root,0,pos_arr,neg_arr);
    //print_array (pos_arr,8) ; 
    //print_array (neg_arr,8) ; 
    //map<int,int> vertical_sum_map;
    //get_vertical_sum_v2 (root,0,vertical_sum_map);
    //get_all_k_v_from_vertical_sum (vertical_sum_map);
    vector<int> tree_list_vector;
    print_sum_from_root_to_leaf (root,0,tree_list_vector);
    print_list (tree_list_vector);
    int dia = tree_diameter (root);
    cout << "the diameter of tree = " << dia << endl;
    int inorder1[] = {7,7};
    int preorder1[] = {7,7};
    //get_mid_elements (preorder,inorder,6);
    bt_node *root1 = 0;
    root1 = build_tree_from_in_pre_order (root1,preorder1,inorder1,2,3);
    traverse_tree_inorder (root1);
    cout << endl;
}
void test_vertical_sum_v1_v2 () {
    int arr[] = {1,2,3,4,5,6,7,8}; 
    bt_node *root = create_bin_tree (arr,8);
    
    int pos_arr[] = {0,0,0,0,0,0,0,0};
    int neg_arr[] = {0,0,0,0,0,0,0,0};
    get_vertical_sum (root,0,pos_arr,neg_arr);
    print_array (pos_arr,8) ; 
    print_array (neg_arr,8) ; 
    map<int,int> vertical_sum_map;
    get_vertical_sum_v2 (root,0,vertical_sum_map);
    get_all_k_v_from_vertical_sum (vertical_sum_map);
}

int main () {
    int arr[] = {1,2,3,4,5,6,7,8}; 
    bt_node *root = create_bin_tree (arr,8);
    traverse_tree_inorder (root);
    cout << endl;
    vector<int> tree_list_vector;
    print_sum_from_root_to_leaf (root,0,tree_list_vector);
    print_list (tree_list_vector);
    test_inorder_preorder ();
    int span_cnt = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    find_total_span_of_bin_tree (root,span_cnt,&min,&max);
    cout << min << "," << max << endl;
    int tree_depth = depth_of_tree (root);
    cout << "the depth of tree = " << tree_depth << endl;
    
    int dia = tree_diameter (root);
    cout << "the diameter of tree = " << dia << endl;
    //test_inorder_postorder ();
    //bt_node *root = 0;
}
