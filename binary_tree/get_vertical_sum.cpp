#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode (int aval) : left(NULL),right(NULL),val(aval) {}
};

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
void get_vertical_sum_v2 (TreeNode *root,int dist,map<int,int>& vertical_sum_map) {
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

int main () {
    //int pos_arr[] = {0,0,0,0,0,0,0,0};
    //int neg_arr[] = {0,0,0,0,0,0,0,0};
    //get_vertical_sum (root,0,pos_arr,neg_arr);
}
