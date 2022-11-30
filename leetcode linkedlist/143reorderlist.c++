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
    void reorderList(ListNode* head) {
        
        // finding mid 
        if(head->next==NULL)
        {
            return;
        }
        ListNode * mid=head;
        ListNode * prev=head;
        ListNode * head1=head;
        while(head1 and head1->next!=NULL)
        {
            prev=mid;
            mid=mid->next;
            if(head1->next==NULL)
            {
                break;
            }
            head1=head1->next;
            if(head1->next==NULL)
            {
                break;
            }
            head1=head1->next;
        }
        prev->next=NULL;
        
        // reversing the right half list;
        ListNode * temp=mid;
        ListNode * prev2=NULL;
        while(temp)
        {
            temp=mid->next;
            mid->next=prev2;
            prev2=mid;
            mid=temp;
        }
        //cout<<prev2->val<<endl;
        ListNode * move1=head;
        ListNode * move2=prev2;
        ListNode * next2=prev2;
        ListNode * next1=head;
        while(move1)
        {
            next2=move2->next;
            next1=move1->next;
            move1->next=move2;
            if(next1!=NULL)
            move2->next=next1;
            move1=next1;
            move2=next2;
        }
        
    }
};
