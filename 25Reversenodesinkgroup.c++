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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans=NULL,*headprev=head;
        int cnt=0;
        while(head)
        {
            cnt++;
            head=head->next;
        }
        head=headprev;
        cnt/=k;
        ListNode *next1;
        while(cnt--)
        {
            ListNode *prev=NULL,*head1=head,*headprev1=head;
            next1=head;
            for(int i=0;i<k;i++)
            {
                next1=head1->next;
                head1->next=prev;
                prev=head1;
                head1=next1;
            }
            if(ans==NULL)
            {
                ans=prev;
            }
            else
            {
                headprev->next=prev;
                headprev=headprev1;
            }
            head=head1;  
        }
        headprev->next=next1;
        return ans; 
    }
};
