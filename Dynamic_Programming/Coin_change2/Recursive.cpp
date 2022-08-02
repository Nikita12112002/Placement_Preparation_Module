long dfs(int nums[] , int i , int tar)
{
    if(i==0)
    {
        if(tar%nums[i]==0)
            return 1;
        return 0;
    }
    int notpick = dfs(nums,i-1,tar);
    int pick=0;
    if(nums[i]<=tar)
        pick = dfs(nums,i,tar-nums[i]);
    return pick+notpick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    int ans=0;
     ans = dfs(denominations,n-1,value);
    if(ans<=0)
        return 0;
    return ans;
}