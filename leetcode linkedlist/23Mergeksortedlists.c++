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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int cnt=0;
        ListNode*ans;
        ListNode*head=new ListNode(10001);
        int pnt;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==NULL)
            {
                cnt++;
                continue;
            }
            if(head->val>=v[i]->val)
            {
                head=v[i];
                pnt=i;
            }
        }
        //return head;
        if(cnt==v.size())
        {
            return NULL;
        }
        ans=head;
        v[pnt]=v[pnt]->next;
        cnt=0;
        while(cnt!=v.size())
        {
            int pnt2;
            ListNode*head2=new ListNode(10001);
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==NULL)  
                {
                    cnt++;
                    continue;
                }
                if(head2->val>=v[i]->val)
                {
                    head2=v[i];
                    pnt2=i;
                }
            }
            if(cnt==v.size())
                break;
            if(pnt2==pnt)
            {
                v[pnt]=v[pnt]->next;
            }
            else
            {
                head->next=head2;
                v[pnt2]=v[pnt2]->next;
            }
            head=head->next;
            pnt=pnt2;
            cnt=0;
        }
        return ans;
        
    }
};
