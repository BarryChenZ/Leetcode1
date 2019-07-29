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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int k = 0;
        vector<vector<int>> res(1000);
        vector<int> temp;
        traversal(root, res, k);
        for(int i = 0; i < res.size(); i++){
            if(res[i].size() == 0) break;
            k++;
        }
        res.resize(k);
        return res;
    }
    void traversal(TreeNode* root, vector<vector<int>>& res, int k){
        if(!root) return;
        res[k].push_back(root->val);
        traversal(root->left, res, k+1);
        traversal(root->right, res, k+1);
    }
};
