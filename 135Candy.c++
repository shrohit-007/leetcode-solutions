class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int,int>>v;
        if(ratings.size()==1)
            return 1;
        vector<int>values(ratings.size(),1);
        for(int i=0;i<ratings.size();i++)
        {
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        //reverse(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            int ind=v[i].second;
            int f=0;
            if(ind>0)
            {
                if(ratings[ind]>ratings[ind-1] and values[ind]<=values[ind-1])
                    values[ind]=values[ind-1]+1;
            }
            if(ind<ratings.size()-1)
            {
                if(ratings[ind]>ratings[ind+1] and values[ind]<=values[ind+1])
                    values[ind]=values[ind+1]+1;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            //cout<<values[i]<<" ";
            ans+=values[i];
        }//cout<<endl;
        return ans;
    }
};
