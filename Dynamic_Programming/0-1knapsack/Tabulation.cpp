int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0]; i<=maxWeight; i++){
        dp[0][i] = value[0];
    }
    for(int i=1 ; i<n ;i++)
    {
        for(int j=0 ;j<maxWeight+1 ;j++)
        {    
      
            int notpick = dp[i-1][j];
            int pick =INT_MIN;
            if(weight[i]<=j)
                pick = value[i]+dp[i-1][j-weight[i]];
            
            dp[i][j]=max(notpick ,pick);
        }
    }
   return dp[n-1][maxWeight];
}