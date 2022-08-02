int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    
        
    for(int i=0; i<=x; i++){
        if(i%nums[0] == 0)  
            dp[0][i] = i/nums[0];
        else dp[0][i] = 1e9;
    }
    
    for(int i=1 ; i<n;i++)
    {
        for(int j=0 ; j<x+1 ;j++)
        {
            
            int nonpick = dp[i-1][j];
            int pick =1e9;
            if(nums[i]<=j)
                pick = 1+dp[i][j-nums[i]];
            
            dp[i][j]=min(pick , nonpick);
        }
    }
    int ans = dp[n-1][x];
    if(ans >=1e9) 
        return -1;
    return ans;
}