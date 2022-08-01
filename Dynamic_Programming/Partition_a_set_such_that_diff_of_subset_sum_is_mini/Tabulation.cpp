int minSubsetSumDifference(vector<int>& a, int n)
{
	// Write your code here.
    int total=0;
    for(int i=0 ;i<n;i++)
      total=total+a[i];
    
    vector<vector<bool>>dp(n,vector<bool>(total+1 , false));
    
    for(int i=0 ; i<n ;i++)
    {
        for(int j=0 ; j<total+1;j++)
        {
            if(j==0)
            {
                dp[i][j]=true;
                continue;
            }
            if(i==0)
            {
                if(a[i]<=j)
                    dp[i][a[i]]=true;
                else
                    dp[i][j]=false;
                continue;
            }
            
            int notpick = dp[i-1][j];
            int pick = false;
            if(a[i]<=j)
                pick = dp[i-1][j-a[i]];
            
           dp[i][j]=notpick || pick;
            
        }
    }
    int mini = 1e9;
    
    for(int i=0 ; i<=total ;i++)
    {
        if(dp[n-1][i]==true)
        {
            int rem = total-i;
            int diff = abs(i-rem);
            mini = min(mini , diff);
        }
    }
    return mini;
}
