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
    vector<int> temp;
    void flatten(TreeNode* root) {
        if(!root) return;
        input(root);
        root->left = NULL;
        for(int i = 1; i < temp.size(); i++){
            TreeNode* tmp = new TreeNode(temp[i]);
            root->right = tmp;
            root = root->right;
        }
        return;
    }
    void input(TreeNode* root){
        if(!root) return;
        temp.push_back(root->val);
        input(root->left);
        input(root->right);
    }
};
