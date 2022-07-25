int f(int n ,vector<int>&h,vector<int>&dp)
{
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);
    if(dp[n]!=-1)
        return dp[n];
    int left = f(n-1,h,dp)+abs(h[n]-h[n-1]);
    int right = f(n-2,h,dp) +abs(h[n]-h[n-2]);
    return dp[n]= min(left,right);
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return f(n-1,h,dp);
}