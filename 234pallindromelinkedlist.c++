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
    bool check(ListNode *head1,ListNode *head2)
    {
        if(head1==NULL and head2==NULL)
            return true;
        if(head1->val==head2->val)
        {
            return check(head1->next,head2->next);
        }
        return false;
    }
    bool isPalindrome(ListNode* head) {
        ListNode * head1=head;
        int cnt=0;
        while(head1)
        {
            cnt++;
            head1=head1->next;
        }
        int n=cnt;
        if(n==1)
        {
            return true; 
        }
        cnt/=2;
        ListNode * temp1=head;
        ListNode * prev=NULL,*next1=head;
        while(cnt>0)
        {
            next1=next1->next;
            temp1->next=prev;
            prev=temp1;
            temp1=next1;
            cnt--;
        }
        if(n&1)
            return check(prev,next1->next);
        return check(prev,next1);
    }
};
