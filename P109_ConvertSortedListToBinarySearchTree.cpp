/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return input(head);
    }
    TreeNode* input(ListNode* head){
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode* tmp = nullptr;
        ListNode* l1 = head;
        ListNode* l2 = head;
        //左邊是頭 右邊要找
        while(l2 != nullptr && l2->next != nullptr){
            tmp = l1;
            l1 = l1->next;
            l2 = l2->next->next;
        }
        tmp->next = nullptr;
        TreeNode* result = new TreeNode(l1->val);
        result->left = input(head);
        result->right = input(l1->next);
        return result;
    }
};
