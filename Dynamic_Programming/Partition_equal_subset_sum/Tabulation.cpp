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
    vector<vector<bool>>dp(n,vector<bool>((sum/2)+1,false));
    
    int k = sum/2;
    
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<k+1 ;j++)
        {
            if(j==0)
            {  
                dp[i][j]=true;
                continue;
            }
            if(i==0)
            {
                if(arr[i]<=j)
                    dp[i][arr[i]]=true;
                else
                    dp[i][j]=false;
                continue;
            }
          bool nonpick = dp[i-1][j];
          bool pick = false;
            if(arr[i]<=j)
             pick = dp[i-1][j-arr[i]];
         dp[i][j]=nonpick || pick;
        }
    }
    return dp[n-1][k];
}
