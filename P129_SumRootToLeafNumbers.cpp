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
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        go(root, temp);
        return res;
    }
    void go(TreeNode* root, vector<int>& temp){
        if(!root) return;
        temp.insert(temp.begin(), root->val);
        if(!root->left && !root->right){
            int count = 0;
            for(int i = 0; i < temp.size(); i++){
                cout << temp[i];
                count += temp[i] * pow(10,i);
            }
            res += count;
            return;
        }
        go(root->left , temp);
        if(root->left ) temp.erase(temp.begin(), temp.begin() + 1);
        go(root->right, temp);
        if(root->right) temp.erase(temp.begin(), temp.begin() + 1);
    }
};
