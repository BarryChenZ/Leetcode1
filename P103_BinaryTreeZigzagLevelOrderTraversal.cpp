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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     int k = 0;
    vector<vector<int>> res(1000);
    vector<int> temp;
    traversal(root, res, k, 0);
    for(int i = 0; i < res.size(); i++){
        if(res[i].size() == 0) break;
            k++;
        }
        res.resize(k);
        return res;
    }
    void traversal(TreeNode* root, vector<vector<int>>& res, int k, int direc){
        if(!root) return;
        if(direc == 0) res[k].push_back(root->val);
        else res[k].insert(res[k].begin(), root->val);
        traversal(root->left, res, k+1, (k+1)%2);
        traversal(root->right, res, k+1, (k+1)%2);
    }
};
