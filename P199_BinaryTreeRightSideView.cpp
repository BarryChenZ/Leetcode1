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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> m;
        if(!root) return ans;
        trace(root, ans, 1);
        return ans;
    }
    void trace(TreeNode* root, vector<int>& ans, int level){
        if(!root) return;
        if(level > ans.size()) ans.push_back(root->val);
        else ans[level - 1] = root->val;
        
        trace(root->left, ans, level + 1);
        trace(root->right, ans, level + 1);
    }
};
