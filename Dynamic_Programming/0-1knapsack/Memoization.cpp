int dfs(vector<int>weight , vector<int>value , int i , int w,vector<vector<int>>&dp)
{
    if(i==0)
    {
        if(weight[i]<=w)
            return value[i];
        return 0;
    }
    if(dp[i][w]!=-1)
        return dp[i][w];
    int notpick = dfs(weight,value,i-1,w,dp);
    int pick =0;
    if(weight[i]<=w)
        pick = value[i]+dfs(weight ,value , i-1 , w-weight[i],dp);
    return dp[i][w]= max(notpick , pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
   return dfs(weight , value , n-1 , maxWeight,dp);
}