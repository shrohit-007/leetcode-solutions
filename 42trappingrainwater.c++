class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int i=0,j=n-1;
		int ans=0;
		int left=0,right=0;
		while(i<=j)
		{
			if(v[i]>left)
			{
				left=v[i];
			}
			if(v[j]>right)
			right=v[j];
			if(v[i]<v[j])
			{
				ans+=left-v[i];
				i++;
			}
			else
			{
				ans+=right-v[j];
				j--;
			}
		}
        return ans;
    }
};
