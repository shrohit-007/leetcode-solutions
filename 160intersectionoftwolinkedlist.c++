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
        ListNode *temp1=headA,*temp2=headB;
        while(headA!=headB)
        {
            headA=headA==NULL?temp2:headA->next;
            headB=headB==NULL?temp1:headB->next;
        }
        return headB;
    }
};
