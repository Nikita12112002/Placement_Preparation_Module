bool dfs(vector<int>&a , int i , int k ,vector<vector<int>>&dp)
{
   if(k==0)
       return true;
    if(i==0)
    {
        if(a[i]==k)
            return true;
        return false;
    }
    if(dp[i][k]!=-1)
        return dp[i][k];
    
   bool nonpick=dfs(a,i-1,k,dp);
    bool pick = false;
    if(a[i]<=k)
    {
    pick = dfs(a,i-1,k-a[i],dp);
    }
    return dp[i][k]=nonpick || pick;
}
bool subsetSumToK(int n, int k, vector<int> &arr ) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
     if(dfs(arr,n-1,k,dp))
         return true;
    return false;
}