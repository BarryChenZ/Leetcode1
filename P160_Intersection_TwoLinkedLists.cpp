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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA){
            sizeA++;
            tempA = tempA->next;
        }
        while(tempB){
            sizeB++;
            tempB = tempB->next;
        }
        if(sizeA > sizeB){
            for(int i = 0; i < sizeA -  sizeB; i++) headA = headA->next;
        }
        else{
            for(int i = 0; i < sizeB -  sizeA; i++) headB = headB->next;
        }
        ListNode* res;
        while(headA){
            if(headA == headB){
                res = headA;
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return res;
    }
};
