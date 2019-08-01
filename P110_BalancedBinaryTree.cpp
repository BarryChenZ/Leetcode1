/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int res = dfs(root);
        return res == -1 ? false : true; 
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == -1 || right == -1) return -1;
        if(abs(left-right) > 1) return -1;
        return 1 + max(left, right);
    } 
};
