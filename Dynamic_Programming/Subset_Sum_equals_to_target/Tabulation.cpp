bool dfs(vector<int>&a , int n , int k ,vector<vector<bool>>&dp)
{
     
    for(int i=0 ;i<n;i++)
    {
        for(int j=0 ;j<k+1;j++)
        {
        
           if(j==0)
           {
               dp[i][j]=true;
               continue;
           }
            if(i==0)
            {
                if(a[i]<=k)
                    dp[i][a[i]]=true;
                else
                    dp[i][j]=false;
                continue;
            }
           
          bool nonpick = dp[i-1][j];
          bool pick = false;
            if(a[i]<=j)
             pick = dp[i-1][j-a[i]];
         dp[i][j]=nonpick || pick;
       }
    }
    return dp[n-1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr ) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
     if(dfs(arr,n,k,dp))
         return true;
    return false;
}