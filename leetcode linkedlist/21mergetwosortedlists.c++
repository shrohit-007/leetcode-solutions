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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL or list2==NULL)
        {
            if(list1==NULL and list2==NULL)
            return NULL;
            if(list1!=NULL)
            return  list1;
            else
                return list2;
        }
        ListNode*ans;
        int f;
        if(list1->val<=list2->val)
        {
            ans=list1;
            f=1;
            list1=list1->next;
        }
        else
        {
            ans=list2;
            f=0;
            list2=list2->next;
        }
        ListNode* head=ans;
        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                if(f)
                list1=list1->next;
                else
                {
                    f=1;
                    head->next=list1;
                    list1=list1->next;
                }
            }
            else
            {
                if(f)
                {
                    f=0;
                    head->next=list2;
                    list2=list2->next;
                }
                else
                {
                    list2=list2->next;
                }
            }
            head=head->next;
        }
        if(list1!=NULL)
        head->next=list1;
        if(list2!=NULL)
            head->next=list2;
        return ans;
    }
};
