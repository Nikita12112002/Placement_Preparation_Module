int f(int n ,vector<int>&h,vector<int>&dp)
{
    if(n==0)
        return 0;
    if(n==1)
        return abs(h[1]-h[0]);
    int prev1=0;
    int prev2=abs(h[1]-h[0]);
    int curr;
    for(int i=2 ;i<=n ;i++)
    {
        int left = prev2+abs(h[i]-h[i-1]);
        int right = prev1+abs(h[i]-h[i-2]);
        curr=min(left,right);
        prev1=prev2;
        prev2=curr;
    }
    return curr;
}
int frogJump(int n, vector<int> &h)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    return f(n-1,h,dp);
}