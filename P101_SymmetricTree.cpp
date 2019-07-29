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
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        if(!root) return res;
        vector<int> temp;
        vector<int> direc;
        input(root, temp, direc, 0);
        if(temp.size()%2 != 1) return false;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] != temp[temp.size() - 1 - i] || direc[i] == direc[direc.size() - 1 - i] && direc[i] != 0){
                res = false;
                break;
            }
        }
        return res;
    }
    void input(TreeNode* root, vector<int>& temp, vector<int>& direc, int i){
        if(!root) return;
        input(root->left, temp, direc, 1);
        temp.push_back(root->val);
        direc.push_back(i);
        input(root->right, temp, direc, 2);
    }
};
