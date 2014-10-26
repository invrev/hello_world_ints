#include<iostream>
#include<queue>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct qTreeLinkNode {
    struct TreeLinkNode* root;
    int level;
};


void connect(TreeLinkNode *root) {
    queue<qTreeLinkNode> linkq;
    vector<qTreeLinkNode> vecq;
    if (root == 0) {
        return;
    }
    linkq.push(root,0);
    while ( ! linkq.isempty() ) {
        qTreeLinkNode* ele = linkq.front();
        vecq.push_back(ele->root,ele->level);
        if (ele->root->left) {
           linkq.push(ele->root->left,ele->level++); 
        }
        if (ele->right->right) {
           linkq.push(ele->root->right,ele->level++); 
        }
        linkq.pop();
    }

    int len = vecq.size();
    TreeNode *prev = NULL;
    int prev_level = 0;
    for (int i=0;i < len;i++) {
       qTreeLinkNode* node =  vecq[i];
       node->root->next = prev;
       prev_level = node->root->level;
       prev = node->root;
    }

}


