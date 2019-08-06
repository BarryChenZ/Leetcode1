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
    int res = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        maxi(root, 0);
        return res;    
    }
    int maxi(TreeNode* root, int curSum){
        if(!root) return curSum;
        int left_sum  = max(0, maxi(root->left,  curSum));
        int right_sum = max(0, maxi(root->right, curSum));
        res = max(res, left_sum + right_sum + root->val);
        return max(left_sum, right_sum) + root->val;
    }
};
