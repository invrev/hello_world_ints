#include<iostream>

//handle negative case
//path can start at any node and end at any node
int lrm(TreeNode *root,int& ans)
    {
        if (NULL == root) return 0;
        int l = lrm(root->left,ans);
        int r = lrm(root->right,ans);
        int temp = root->val;
        temp = max(temp, temp + l);
        temp = max(temp, temp + r);
        ans = max(ans, temp);
        return max(root->val, root->val + max(l, r));
    }


int maxPathSum(TreeNode *root) {
        int ans = root->val;
        lrm(root,ans);
        return ans;
    }

 //TODO : Handle the negative cases like -2,-
int sum_with_trav (TreeNode *root) {
    int sum = 0;
    if (root) {
        sum += (root->val + sum_with_trav (root->left) + sum_with_trav (root->right) );
        
    } else {
        return -999;
    }
   return sum;
}
int maxPathSum (TreeNode* root) {
    if (root && root->left == 0 && root->right == 0) {
        return root->val;
    }
    else if (root) {
        int currentSum = root->val;
        int leftSum = sum_with_trav (root->left);
        int rightSum = sum_with_trav (root->right);
        int tmpSum =  leftSum  + rightSum + currentSum;
        int maxSum =  max (tmpSum,leftSum);
        maxSum = max (maxSum,rightSum);
        maxSum = max (maxSum,currentSum);
        return max ( maxSum , max (maxPathSum (root->left),maxPathSum (root->right) ) );
}


int main () {
}
