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
    int countGood(TreeNode* root, int maxSoFar) {
        if(root==nullptr){
            return 0;
        }
        int good=0;
        if(root->val>=maxSoFar){
            good=1;
        }
        int newMax=max(root->val,maxSoFar);
        int left=countGood(root->left,newMax);
        int right=countGood(root->right, newMax);
        return good+left+right;

    }

    int goodNodes(TreeNode* root) {
        return countGood(root,root->val);
    }
};
