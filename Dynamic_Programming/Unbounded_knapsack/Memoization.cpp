int dfs(int i , int wt , vector<int>&profit , vector<int>&nums , vector<vector<int>>&dp)
{
    if(i==0)
    {
         return ((int)wt/nums[0])*profit[i];
       
    }
    if(dp[i][wt]!=-1)
        return dp[i][wt];
    int notpick = dfs(i-1,wt,profit,nums,dp);
    int pick=-1e9;
    if(nums[i]<=wt)
        pick = profit[i]+dfs(i,wt-nums[i],profit,nums,dp);
    
    return dp[i][wt]=max(notpick,pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return dfs(n-1,w,profit,weight,dp);
    
}
