int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    int sz = price.size();
    vector<vector<int>>dp(sz,vector<int>(n+1,0));
    
    for(int j=0 ; j<n+1 ;j++)
    {
        dp[0][j]=j*price[0];
    }
    for(int i=1 ; i<sz ;i++)
    {
        for(int j=0 ; j<n+1 ;j++)
        {
             int notpick = dp[i-1][j];
             int pick = -1e9;
    int rodlen = i+1;
    if(rodlen<=j)
        pick = price[i]+dp[i][j-rodlen];
     dp[i][j] = max(notpick , pick);
        }
    }
    return dp[sz-1][n];
}
