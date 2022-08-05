class Solution {
public:
    
     int dfs(vector<int>&prices , int i , int buy ,int n , vector<vector<int>>&dp , int fee)
    {
        if(i>=n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        
        if(buy==1)
        {
            return dp[i][buy]=max(-prices[i]+dfs(prices,i+1,0,n,dp,fee) , 0+dfs(prices,i+1,1,n,dp,fee));
        }
          return dp[i][buy]=max(prices[i]-fee+dfs(prices,i+1,1,n,dp,fee) , 0+dfs(prices,i+1,0,n,dp,fee));
        
            
    }
    int maxProfit(vector<int>& prices , int fee) {
         int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return dfs(prices,0,1,n,dp,fee);
    }
};