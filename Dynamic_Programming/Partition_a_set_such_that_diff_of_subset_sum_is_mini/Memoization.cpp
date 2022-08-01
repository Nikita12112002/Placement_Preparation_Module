bool dfs(vector<int>&a , int i , int target , vector<vector<int>>&dp)
{
    if(target==0)
        return dp[i][target]=true;
    if(i==0)
    {
        if(a[0]==target)
            dp[i][target]=true;
        else
            dp[i][target]=false;
    }
    
    if(dp[i][target]!=-1)
        return dp[i][target];
    int notpick = dfs(a,i-1,target,dp);
    int pick = false;
    if(a[i]<=target)
        pick= dfs(a,i-1,target-a[i],dp);
    
    return dp[i][target]=notpick || pick;
        
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int total=0;
    for(int i=0 ;i<n;i++)
      total=total+arr[i];
    
    vector<vector<int>>dp(n,vector<int>(total+1 , -1));
    
    int mini = 1e9;
    for(int j=0 ;j<total+1 ;j++)
    {
        dfs(arr,n-1,j,dp);
    }
    for(int i=0 ; i<=total ;i++)
    {
        if(dp[n-1][i]==true)
        {
            int rem = total-i;
            int diff = abs(i-rem);
            mini = min(mini , diff);
        }
    }
    return mini;
}
