int dfs(int i , int j , vector<int>&nums , vector<vector<int>>&dp)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini=1e9;
    for(int k=i ;k<j ;k++)
    {
        int steps = nums[i-1]*nums[k]*nums[j]+dfs(i,k,nums,dp)+dfs(k+1,j,nums,dp);
        if(steps<mini)
            mini=steps;
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return dfs(1,n-1,arr,dp);
}