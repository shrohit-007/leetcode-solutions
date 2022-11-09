class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>s;
    int next(int price) {
        int cnt=0;
        while(!s.empty() and s.top().first<=price)
        {
            int c=s.top().second;
            cnt+=c;
            s.pop();
        }
        cnt++;
        s.push({price,cnt});
       // cout<<price<<" "<<cnt<<" "<<s.size()<<endl;
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
