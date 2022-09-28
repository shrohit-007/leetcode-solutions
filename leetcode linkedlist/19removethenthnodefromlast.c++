class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *head1=head;
        int cnt=1;
        while(head->next!=NULL)
        {
            head=head->next;
            cnt++;
        }
        int startn=cnt-n;
        cnt=0;
        head=head1;
        if(startn==0)
        {
            return head->next;
        }
        while(cnt!=startn-1)
        {
            head1=head1->next;
            cnt++;
        }
        head1->next=head1->next->next;
        return head;
        
        
    }
};
