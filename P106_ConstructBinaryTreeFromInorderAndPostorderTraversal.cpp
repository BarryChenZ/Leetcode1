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
    int postIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* res;
        postIndex = postorder.size() - 1;
        res = build(postorder, inorder, 0, inorder.size() - 1);
        return res;
    }
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int start, int end){
        if(start > end) return NULL;
        
        TreeNode* newNode = new TreeNode(postorder[postIndex--]);
        if(start == end) return newNode;
        
        int index = search(inorder, start, end, newNode->val);
        
        newNode->right = build(postorder, inorder, index + 1, end);
        newNode->left  = build(postorder, inorder, start, index - 1);  
        
        return newNode;
    }
    int search(vector<int>& inorder, int start, int end, int value){
        for(int i = start; i <= end; i++){
            if(inorder[i] == value) return i;
        }
        return 0;
    }
};
