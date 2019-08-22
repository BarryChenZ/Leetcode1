/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* tmp;
    BSTIterator(TreeNode* root) {
        tmp = root;
    }
    
    /** @return the next smallest number */
    int next() {
        int num = 0;
        TreeNode* temp = tmp;
        // left 空
        if(temp->left == NULL){
            tmp = tmp->right;
            return temp->val;
        }
        //find and delete
        while(temp->left->left != NULL){
            temp = temp->left;
        }
        num = temp->left->val;
        if(temp->left->right != NULL){
            temp->left = temp->left->right;
        }
        else{
            temp->left = NULL;
        }
        return num;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(tmp == NULL) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
