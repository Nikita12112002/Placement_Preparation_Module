bool dfs(vector<int>&a , int i , int target , vector<vector<int>>&dp)
{
    if(target==0)
        return true;
    if(i==0)
    {
        if(a[i]==target)
            return true;
        return false;
    }
    
    if(dp[i][target]!=-1)
        return dp[i][target];
    
   bool nonpick = dfs(a,i-1,target,dp);
    bool pick =false;
    if(a[i]<=target)
    pick = dfs(a,i-1,target-a[i],dp);
    
    return dp[i][target] =pick||nonpick;
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int sum=0;
    for(int i=0 ;i<arr.size() ;i++)
    {
        sum=sum+arr[i];
    }
    
    if(sum%2!=0)
        return false;
    vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
    if(dfs(arr,n-1,sum/2,dp))
        return true;
    return false;
}
