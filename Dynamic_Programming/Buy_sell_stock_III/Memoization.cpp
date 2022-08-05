class Solution {
public:
    int dfs(vector<int>&prices , int i , int buy , int cap ,int n , vector<vector<vector<int>>>&dp)
    {
        if(cap==0)
            return 0;
        if(i==n)
            return 0;
        
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        
        if(buy)
            return dp[i][buy][cap]=max(-prices[i]+dfs(prices,i+1,0,cap,n,dp) , 0+dfs(prices,i+1,1,cap,n,dp));
        else
            return dp[i][buy][cap]=max(prices[i]+dfs(prices,i+1,1,cap-1,n,dp) , dfs(prices,i+1,0,cap,n,dp));
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return dfs(prices,0,1,2,n,dp);
    }
};