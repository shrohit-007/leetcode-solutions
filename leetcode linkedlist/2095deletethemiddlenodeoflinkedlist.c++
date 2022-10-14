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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0,cnt=0;
        ListNode *head1=head;
        while(head!=NULL)
        {
            n++;
            head=head->next;
        }
        n/=2;
        if(n==0)
        {
            return NULL;
        }
        ListNode*prev;
        head=head1;
        while(head!=NULL)
        {
            prev=head;
            head=head->next;
            cnt++;
            if(cnt==n)
            {
                break;
            }
        }
        prev->next=prev->next->next;
        return head1;
    }
};
