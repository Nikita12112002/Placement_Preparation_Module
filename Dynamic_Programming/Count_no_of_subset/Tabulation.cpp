int findWays(vector<int> &nums, int tar)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    
    for(int i=0 ;i<n;i++)
    {
        for(int j=0 ;j<tar+1;j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
                continue;
            }
            if(i==0)
            {
                if(nums[i]==j)
                {
                    dp[i][nums[i]]=1;
                }
                else
                    dp[i][j]=0;
                continue;
            }
            
            int nonpick = dp[i-1][j];
            int pick =0;
            if(nums[i]<=j)
                pick = dp[i-1][j-nums[i]];
            dp[i][j]=pick+nonpick;
        }
    }
    return dp[n-1][tar];
}