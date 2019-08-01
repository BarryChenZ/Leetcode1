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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        check(root, sum, temp);
        return res;
    }
    void check(TreeNode* root, int sum, vector<int> temp){
        if(!root) return;
        sum -= root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == 0) {
                res.push_back(temp);
                return;
            }
        }
        check(root->left, sum, temp);
        check(root->right, sum, temp);
    }
};
