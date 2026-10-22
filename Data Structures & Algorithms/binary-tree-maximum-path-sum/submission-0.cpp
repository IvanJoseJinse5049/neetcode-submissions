/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int calSum(TreeNode* root, int &maxSum){
        if(root==nullptr){
            return 0;
        }
        int left = calSum(root->left,maxSum);
        int right = calSum(root->right,maxSum);
        maxSum = max(root->val + max(left,0)+max(right,0),maxSum);
        return root->val + max(0,max(left,right));
    }
    
    int maxPathSum(TreeNode* root) {
       int maxSum = INT_MIN;
       calSum(root,maxSum);
       return maxSum;
    }
};
