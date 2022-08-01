int dfs(vector<int>&num , int tar , int i)
{
    if(i==0)
    {
        if(tar==0 && num[0]==0)
            return 2;
        if(tar==0 || tar==num[0])
            return 1;
        return 0;
    }
    int notpick = dfs(num,tar,i-1);
    int pick =0;
    if(num[i]<=tar)
        pick = dfs(num ,tar-num[i],i-1);
    return pick+notpick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    return dfs(num,tar,n-1);
}