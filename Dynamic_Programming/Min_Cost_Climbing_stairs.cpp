class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        
        int n=costs.size() ;
        vector<int>dp(n+1);
        dp[0]=costs[0], dp[1]=costs[1];
        
        if(n==0)
            return 0;
        
        if(n==1)
            return costs[0];
        
        for(int i=2 ;i<n;i++)
        {
           dp[i]= costs[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};