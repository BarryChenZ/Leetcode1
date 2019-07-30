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
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res;
        res = build(preorder, inorder, 0, preorder.size() - 1);
        return res;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[preIndex++]);
        if(start == end) return newNode;
        
        int index = search(inorder, start, end, newNode->val);
        
        newNode->left  = build(preorder, inorder, start, index - 1);  
        newNode->right = build(preorder, inorder, index + 1, end);
        
        return newNode;
    }
    int search(vector<int>& inorder, int start, int end, int value){
        for(int i = start; i <= end; i++){
            if(inorder[i] == value) return i;
        }
        return 0;
    }
};
