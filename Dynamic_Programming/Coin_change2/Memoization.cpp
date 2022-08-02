#include<bits/stdc++.h>
long dfs(int nums[] , int i , int tar ,vector<vector<long>>&dp)
{
    if(i==0)
    {
        if(tar%nums[i]==0)
            return 1;
        return 0;
    }
    if(dp[i][tar]!=-1)
        return dp[i][tar];
    long notpick = dfs(nums,i-1,tar,dp);
    long pick=0;
    if(nums[i]<=tar)
        pick = dfs(nums,i,tar-nums[i],dp);
    return dp[i][tar]=pick+notpick;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    long  ans=0;
      vector<vector<long>>dp(n,vector<long>(value+1,-1));
     return dfs(denominations,n-1, value, dp);

}
      
    
    
