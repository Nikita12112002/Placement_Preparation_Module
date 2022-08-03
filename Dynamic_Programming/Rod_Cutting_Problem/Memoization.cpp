int dfs(vector<int>&price , int i , int tar , vector<vector<int>>&dp)
{
    if(i==0)
    {
        // since the rod at 0 ind is of length 1
        return tar*price[0];
    }
    
    if(dp[i][tar]!=-1)
        return dp[i][tar];
    int notpick = dfs(price , i-1 , tar ,dp);
    int pick = -1e9;
    int rodlen = i+1;
    if(rodlen<=tar)
        pick = price[i]+dfs(price , i , tar-rodlen ,dp);
    return dp[i][tar] = max(notpick , pick);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    int sz = price.size();
    vector<vector<int>>dp(sz,vector<int>(n+1,-1));
    return dfs(price,n-1,n,dp);
}
