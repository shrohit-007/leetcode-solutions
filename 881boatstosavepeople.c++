class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        // map approach 
        // map<int,int>m;
        // for(int i=0;i<people.size();i++)
        // {
        //     if(people[i]<=limit)
        //     m[people[i]]++;
        // }
        // while(!m.empty())
        // {
        //     auto it=m.begin();
        //     m[it->first]--;
        //     cout<<it->first<<endl;
        //     int next=limit-it->first;
        //     if(m[it->first]==0)m.erase(it);
        //     auto it1=m.lower_bound(next);
        //     if(it1!=m.end())
        //     {
        //         if(it1->first==next)
        //         {
        //             m[next]--;
        //             if(m[next]==0)m.erase(it1);
        //         }
        //         else
        //         {
        //             if(it1!=m.begin())
        //             {
        //                 it1--;
        //                 m[it1->first]--;
        //                 if(m[it1->first]==0)m.erase(it1);
        //             }
        //         }
        //     }
        //     else
        //     {
        //         if(it1!=m.begin())
        //         {
        //             it1--;
        //             m[it1->first]--;
        //             if(m[it1->first]==0)m.erase(it1);
        //         }
        //     }
        //     ans++;    
        // }
        
        
        // two pointers method
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            ans++;
        }
        return ans;
    }
};
