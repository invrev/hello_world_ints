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


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

    vector<vector<int> > result;
    if (root==NULL)  {
        return result;
    }else {
        vector<int> tmp_vec;
        queue<TreeNode*> bfs_q;
        bfs_q.push(root);
        //These 2 variables are used to avoid use of extra variable in the struct
        int next_visited = 0;
        int curr_visited = 1;
        bool is_left_to_right = false;
        while (!bfs_q.empty()) {
            TreeNode* tmp_node = bfs_q.front();
            bfs_q.pop();
            curr_visited--;
            tmp_vec.push_back(tmp_node->val);
            if (tmp_node->left) {
                bfs_q.push(tmp_node->left);
                next_visited ++;
            } 
            if (tmp_node->right) {
                bfs_q.push(tmp_node->right);
                next_visited ++;

            }
            if (curr_visited == 0 ) {
                if (is_left_to_right) {
                    reverse(tmp_vec.begin(),tmp_vec.end());
                }
                //Add the tmp_vec to result vector
                result.push_back(tmp_vec);
                tmp_vec.clear();
                curr_visited = next_visited;
                next_visited = 0;
                is_left_to_right = !is_left_to_right;
            }
        }
    }
    return result;
}



int main () {

}


