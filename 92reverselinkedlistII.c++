/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        int cnt=1;
        ListNode * temp1=head;
        ListNode * prev=NULL;
        ListNode * prev1=NULL;
        while(cnt<=left)
        {
            prev1=prev;
            prev=temp1;
            temp1=temp1->next;
            cnt++;
        }
        prev->next=NULL;
        //cout<<prev1->val<<endl;
        if(prev1!=NULL)
        prev1->next=NULL;
        ListNode* next1=temp1;
        ListNode* iniprev=prev;
        //cout<<temp1->val<<" "<<prev->val<<" "<<next1->val<<endl;
        while(left<right)
        {
            next1=next1->next;
            temp1->next=prev;
            prev=temp1;
            //cout<<temp1->next->val<<endl;
            temp1=next1;
            left++;
        }
        //cout<<prev->val<<" "<<prev->next->val<<" "<<prev->next->next->val<<endl;
        if(prev1!=NULL)
        prev1->next=prev;
        else
            head=prev;
        iniprev->next=temp1;
        return head;
    }
};
