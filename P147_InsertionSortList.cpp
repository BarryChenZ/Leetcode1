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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* top = head;
        if(!head || !head->next) return head;
        ListNode* next_n = head->next;
        int i = 1;
        top->next = NULL;
        while(next_n){
            cout << top->val;
            int temp = next_n->val;
            ListNode* tmp = top;
            ListNode* before_tmp = tmp;
            for(int j = 0; j < i; j++){
                if(tmp->val >= temp) break;
                before_tmp = tmp;
                tmp = tmp->next;
            }
            //插頭 插尾 插中間
            ListNode* insert = next_n -> next;
            if(tmp == top){
                next_n -> next = top;
                top = next_n;
            }
            else if(tmp == next_n){
            }
            else{
                ListNode* insert_pos = before_tmp->next;
                before_tmp->next = next_n;
                next_n->next = insert_pos;
            }
            next_n = insert;
            i++;
        }
        return top;
    }
};
