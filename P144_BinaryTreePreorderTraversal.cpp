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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traval(root, res);
        return res;
    }
    void traval(TreeNode* root, vector<int>& res){
        if(!root) return;
        res.push_back(root->val);
        traval(root->left , res);
        traval(root->right, res);
    }
};
