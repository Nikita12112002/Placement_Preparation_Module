int f(vector<vector<int>>& grid ,int i, int j , int n,vector<vector<int>>&dp)
{
    if(i==n-1)
        return grid[n-1][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int down= grid[i][j] + f(grid,i+1,j,n,dp);
    int dia = grid[i][j] + f(grid,i+1,j+1,n,dp);
    
    return dp[i][j]=min(down,dia);
    
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(triangle,0,0,n,dp);
}