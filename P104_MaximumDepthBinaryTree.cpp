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
        Depth(k+1, root->right);
        Depth(k+1, root->left);
    }
};
