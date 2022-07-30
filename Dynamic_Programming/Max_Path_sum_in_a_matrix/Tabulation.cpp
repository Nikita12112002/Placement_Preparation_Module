int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>>dp(n,vector<int>(m,-1));
  
     for(int i=0 ; i<n ;i++)
     {
         for(int j=0 ;j<m ;j++)
         {
             if(i==0)
             {
                 dp[i][j]=matrix[i][j];
                 continue;
             }
             
             int up,left,right;
             
              up = matrix[i][j] + dp[i-1][j];
             
             if(j>0)
                left = matrix[i][j] + dp[i-1][j-1];
             else
                 left= matrix[i][j] + (-1e9);
             if(j<m-1)
              right = matrix[i][j]+dp[i-1][j+1];
             else
                 right = matrix[i][j] + (-1e9);
             
             dp[i][j]=max(up,max(left,right));
         }
     }
  
    for(int j=0; j<m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;

}