#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeLevel {
    int level;
    TreeNode* node;
    TreeNodeLevel(TreeNode* aNode,int aLevel) : level(aLevel) ,node(aNode) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

    vector<vector<int> > result;
    if (root==NULL) return result;
    queue<TreeNodeLevel> q;
    q.push(TreeNodeLevel(root, 0));
    int prev_level = -1;
    int  this_level = -1;

    while (q.size() > 0){
        TreeNodeLevel elem = q.front();
        TreeNode* this_node = elem.node;
        this_level = elem.level;
        q.pop();
        // push to the result.
        if (this_level != prev_level){
            // reverse prev level result if cur level is even
            if (this_level > 0 && this_level%2==0 )  {
                reverse(result.back().begin(), result.back().end());
            }
            prev_level = this_level;
            result.push_back(vector<int>(1,this_node->val));
        } else {
            result.back().push_back(this_node->val);
        }

        // push the children to the q
        if (this_node->left != NULL) q.push(TreeNodeLevel(this_node->left, this_level+1));
        if (this_node->right !=NULL) q.push(TreeNodeLevel(this_node->right, this_level+1));
    }

    if (this_level%2==1) reverse(result.back().begin(), result.back().end());
    return result;
}



int main () {

}


