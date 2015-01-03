#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;

//given tree find the sum of all nodes at level k
struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int data;
};

int returnSumAtLevelK (TreeNode* root,int k) {
    int sum = 0;
    if (!root) {
        return sum;
    }
    queue<TreeNode *> qStore;
    qStore.push(root);
    while (!qStore.empty()) {
        TreeNode *tmp = qStore.front();
        if (k == 0) {
            break;
        }
        if (tmp->left) {
            qStore.push(tmp->left);
        }
        if (tmp->right) {
            qStore.push(tmp->right);
        }
        k--;
        qStore.pop();
    }

    if (k == 0) {
        while (!qStore.empty()) {
            TreeNode *tmp = qStore.front();
            int tmpData = tmp->data;
            sum += tmpData;
            qStore.pop();
        }
    }
    return (sum);
}

int main () {

}


