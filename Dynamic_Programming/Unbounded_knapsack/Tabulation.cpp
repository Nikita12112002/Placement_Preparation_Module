int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &nums)
{
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int j=0 ; j<w+1;j++)
    {
        dp[0][j]= ((int)j/nums[0])*profit[0];
    }
    
    for(int i=1 ; i<n ;i++)
    {
        for(int j=0 ; j<w+1 ;j++)
        {
            int notpick = dp[i-1][j];
            int pick=-1e9;
            if(nums[i]<=j)
               pick = profit[i]+dp[i][j-nums[i]];
    
          dp[i][j]=max(notpick,pick);
        }
    }
   return dp[n-1][w];
    
}
