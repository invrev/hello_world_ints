#include<iostream>
using namespace std;

//The idea is simple. Use a queue to store the nodes level by level, and count the total number of nodes at each level. While popping elements from the queue, if not the last element at the level
//, let the next of it be the front of the queue; otherwise, let the next of it be NULL.
struct TreeLinkNode {
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};


void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> nodes;
        nodes.push(root);
        int left = 1;
        int level =0;
        while(!nodes.empty()){
            TreeLinkNode *temp;
            temp = nodes.front();
            nodes.pop();

            if(temp->left){
                nodes.push(temp->left);
                level++;
            }
            if(temp->right){
                nodes.push(temp->right);
                level++;
            }
            if(left == 1){
                temp->next = NULL;
                left--;
            }
            else{
                temp->next = nodes.front();
                left--;
            }
            if(left==0){
                left = level;
                level =0;
            }

        }
}

//assumption perfect binary tree use of recursion


public void connect(TreeLinkNode root) {
    if (root == null || root.left == null) return;
    root.left.next = root.right;
    if (root.next != null) root.right.next = root.next.left;
    connect(root.left);
    connect(root.right);
}

int main () {

}
