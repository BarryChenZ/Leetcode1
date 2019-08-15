/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        quicksort(head, nullptr);
        return head;
    }
    ListNode* partition(ListNode* head, ListNode* tail){
        int value = head->val;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != tail){
            if(value > q->val){
                p = p->next;
                swap(p->val, q->val);
            }
            q = q->next;
        }
        swap(head->val, p->val);
        return p;
    }
    void quicksort(ListNode* head, ListNode* tail){
        if(head != tail && head){
            ListNode* pivot = partition(head, tail);
            quicksort(head, pivot);
            quicksort(pivot->next, tail);
        }
    }
};
