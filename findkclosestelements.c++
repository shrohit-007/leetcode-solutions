class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i,j;
        vector<int>ans;
        int n=arr.size();
        multiset<int>m;
        for(int i=0;i<n;i++)
        {
            m.insert(arr[i]);
        }
        while(k>0)
        {
            auto it=m.lower_bound(x);
            if(it==m.begin())
            {
                while(k>0)
                {
                    ans.push_back(*it);
                    k--;
                    it++;
                }
                break;
            }
            if(it==m.end())
            {
                --it;
                while(k>0)
                {
                    ans.push_back(*it);
                    k--;
                    --it;
                }
                break;
            }
            if(*it==x)
            {
                ans.push_back(x);
                m.erase(it);
                k--;
                continue;
            }
            auto it1=it;
            it--;
            if(abs(*it1-x)<abs(*it-x))
            {
                //cout<<"YES"<<endl;
                ans.push_back(*it1);
                k--;
                m.erase(it1);
            }
            else
            {
                ans.push_back(*it);
                k--;
                m.erase(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
