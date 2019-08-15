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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traval(root, res);
        return res;
    }
    void traval(TreeNode* root, vector<int>& res){
        if(!root) return;
        traval(root->left, res);
        traval(root->right, res);
        res.push_back(root->val);
    }
};
