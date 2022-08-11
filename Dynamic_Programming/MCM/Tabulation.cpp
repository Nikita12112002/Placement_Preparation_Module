
int matrixMultiplication(vector<int> &nums, int n)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(n,0));
    
    for(int i=0 ; i<n ; i++)
      dp[i][i]=0;
    
    for(int i=n-1 ;i>0 ; i--)
    {
        for(int j=i+1 ; j<n ;j++)
        {
              int mini=1e9;
             for(int k=i ;k<j ;k++)
             {
               int steps = nums[i-1]*nums[k]*nums[j]+dp[i][k]+dp[k+1][j];
                 if(steps<mini)
                   mini=steps;
             }
              dp[i][j]=mini;
        }
    }
    
    return dp[1][n-1];
}