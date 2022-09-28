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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(l1->val+l2->val);
        ListNode *ans=head;
        int carry=0;
        if(l1->val+l2->val>=10)
        {
            head->val=(head->val%10);
            carry=1;
        }
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL or l2!=NULL)
        {
            int val1=0,val2=0;
            if(l1!=NULL)
            {
                val1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                val2=l2->val;
                l2=l2->next;
            }
            val1+=val2;
            ListNode* newnode=new ListNode(val1);
            if(carry)
            {
                newnode->val+=1;
                carry=0;
            }
            if(newnode->val>=10)
            {
                carry=1;
                newnode->val%=10;
            }
            head->next=newnode;
            head=newnode;
        }
        if(carry)
        {
            ListNode*newnode=new ListNode(1);
            head->next=newnode;
        }
        return ans;
    }
};
