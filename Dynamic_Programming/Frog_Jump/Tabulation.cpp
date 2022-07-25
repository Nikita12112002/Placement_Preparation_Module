int f(int n ,vector<int>&h,vector<int>&dp)
{
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=2 ;i<=n ;i++)
    {
        int left = dp[i-1]+abs(h[i]-h[i-1]);
        int right = dp[i-2]+abs(h[i]-h[i-2]);
        dp[i]=min(left,right);
    }
    return dp[n];
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return f(n-1,h,dp);
}