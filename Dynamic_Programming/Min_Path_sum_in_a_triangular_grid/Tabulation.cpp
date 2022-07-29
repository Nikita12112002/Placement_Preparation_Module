int f(vector<vector<int>>& grid , int n,vector<vector<int>>&dp)
{
    for(int i=n-1 ;i>=0 ;i--)
    {
        for(int j=i ; j>=0 ;j--)
        {
            if(i==n-1)
            {
                dp[i][j]=grid[n-1][j];
                continue;
            }
            int down= grid[i][j] + dp[i+1][j];
            int dia = grid[i][j] + dp[i+1][j+1];
            dp[i][j]=min(down,dia);
        }
    }
    
    return dp[0][0];
    
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return f(triangle,n,dp);
}