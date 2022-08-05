class Solution {
public:
    int dfs(vector<int>&prices , int i , int buy , int cap ,int n)
    {
        if(cap==0)
            return 0;
        if(i==n)
            return 0;
        
        if(buy)
            return max(-prices[i]+dfs(prices,i+1,0,cap,n) , 0+dfs(prices,i+1,1,cap,n));
        else
            return max(prices[i]+dfs(prices,i+1,1,cap-1,n) , dfs(prices,i+1,0,cap,n));
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        return dfs(prices,0,1,2,n);
    }
};