#include<iostream> 
#include<queue>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Massaging the existing data-structure to store more information
typedef struct NodeLevel {
    int level;
    TreeNode *node;
    NodeLevel (int alevel,TreeNode *anode) : level(alevel) ,node (anode) {}
} NodeLevel;



vector<vector<int> > levelOrder(TreeNode *root) {
    vector <vector <int> > level_vec;
    queue<NodeLevel *> level_q;
    int level = 1;
    if (root) {
        level_q.push(new TreeNodeLevel(level,root));
        level_vec.resize(level);
        while(!level_q.empty()) {
            NodeLevel *temp = level_q.front();
            root = temp->node;
            int insert_level = (temp->level);
            level_vec[insert_level - 1].push_back(root->val);
            level_q.pop();
            if (root->left || root->right) {
                insert_level += 1;
                level_vec.resize(insert_level);
            }
            if (root->left) {
                level_q.push(new TreeNodeLevel(insert_level,root->left));
            }
            if (root->right) {
              level_q.push(new TreeNodeLevel(insert_level,root->right));   
            }
        }
    }
    return level_vec;
    //return reverse(level_vec.begin(),level_vec.end());
}
