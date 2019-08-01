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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        bool res = redundancy(root, sum);
        return res;
    }
    bool redundancy(TreeNode* root, int sum){
        bool temp = false;
        if(!root) return false;
        sum -= root->val;
        if(!root->left && !root->right){
            if(sum == 0) return true;
        }
        temp = redundancy(root->left, sum);
        if(temp == false) temp = redundancy(root->right, sum);
        return temp;
    }
};
