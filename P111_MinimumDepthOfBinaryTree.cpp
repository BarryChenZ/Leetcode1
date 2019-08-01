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
    int res = 10000;
    int minDepth(TreeNode* root) {
        int k = 1;
        Depth(k, root);
        if(!root) res = 0;
        return res;
    }
    void Depth(int k, TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            if( k < res) res = k;
            return;
        }
        Depth(k+1, root->right);
        Depth(k+1, root->left);
    }
};
