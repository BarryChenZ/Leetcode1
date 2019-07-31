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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        int mid = nums.size()/2;
        TreeNode* res = NULL;
        if(size == 0) return res;
        TreeNode* tmp = new TreeNode(nums[mid]);
        res = tmp;
        heightbalance(nums, 0, mid - 1, res);
        heightbalance(nums, mid + 1, size - 1, res);
        return res;
    }
    void heightbalance(vector<int>& nums, int start, int end, TreeNode* res){
        if(start > end) return;
        int mid;
        if((start + end)%2 == 0) mid = (start + end)/2;
        else mid = (start + end)/2 + 1;
        cout << mid << endl;
        TreeNode* temp = new TreeNode(nums[mid]);
        if(res->val > temp->val){
            res->left = temp;
            res = res->left;
        }
        else{
            res->right = temp;
            res = res->right;
        }
        heightbalance(nums, start, mid - 1, res);
        heightbalance(nums, mid + 1, end, res);
    }
};
