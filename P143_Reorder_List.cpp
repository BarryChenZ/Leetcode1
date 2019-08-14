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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* temp = head;
        ListNode* first = head;
        int size = 0, t = 0;
        while(temp){
            size++;
            temp = temp -> next;
        }
        recur(head, first, size, t);
    }
    void recur(ListNode* h, ListNode* &first, int size, int& t){
        if(h->next) recur(h->next, first, size, t);
        if(t == size/2) return;
        ListNode* temp = first->next;
        first->next = h;
        first = temp;
        h->next = first;
        t++;
        if(t == size/2) first->next = NULL;
    }
};
