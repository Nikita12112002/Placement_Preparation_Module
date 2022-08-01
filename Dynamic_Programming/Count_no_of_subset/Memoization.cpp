int dfs(vector<int>&num , int tar , int i , vector<vector<int>>&dp)
{
    
    if(i==0)
    {
       if(tar==0 && num[0]==0)
           return 2;
        if(tar==0 || tar==num[0])
            return 1;
        return 0;
    }
    if(dp[i][tar]!=-1)
        return dp[i][tar];
    int notpick = dfs(num,tar,i-1,dp);
    int pick =0;
    if(num[i]<=tar)
        pick = dfs(num ,tar-num[i],i-1,dp);
    return dp[i][tar]=pick+notpick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return dfs(num,tar,n-1,dp);
}