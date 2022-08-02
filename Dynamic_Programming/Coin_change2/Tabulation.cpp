#include<bits/stdc++.h>
long dfs(int nums[] , long n , long tar ,vector<vector<long>>&dp)
{
    for(long i=0 ; i<=tar ; i++)
    {
        if(i%nums[0]==0)
            dp[0][i]=1;
        
    }
    
   for(long i=1 ; i<n;i++)
    {
        for(long j=0 ; j<tar+1 ;j++)
        {
            
            long nonpick = dp[i-1][j];
            long pick =0;
            if(nums[i]<=j)
                pick = dp[i][j-nums[i]];
            
            dp[i][j]=pick+nonpick;
        }
    }
    return dp[n-1][tar];
   
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
   
      vector<vector<long>>dp(n,vector<long>(value+1,0));
     return dfs(denominations,n, value, dp);

}
      
    
    
