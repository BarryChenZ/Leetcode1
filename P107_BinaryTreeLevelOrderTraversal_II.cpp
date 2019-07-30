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
    int res = 0;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int k = maxDepth(root);
        vector<vector<int>> result(k);
        traversal(root, result, k - 1);
        return result;
    }
    int maxDepth(TreeNode* root) {
        int k = 0;
        Depth(k, root);
        return res;
    }
    void Depth(int k, TreeNode* root){
        if(!root){
            if(k > res) res = k;
            return;
        }
        Depth(k + 1, root->right);
        Depth(k + 1, root->left);
    }
    void traversal(TreeNode* root, vector<vector<int>>& res, int k){
        if(!root) return;
        res[k].push_back(root->val);
        traversal(root->left, res, k - 1);
        traversal(root->right, res, k - 1);
    }
};
