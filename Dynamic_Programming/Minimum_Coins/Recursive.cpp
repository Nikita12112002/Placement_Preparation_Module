int dfs(vector<int>&nums , int i , int tar)
{
    if(i==0)
    {
        if(tar%nums[i]==0)
            return tar/nums[i];
        else 
            return 1e9;
     }
    int notpick = dfs(nums,i-1,tar);
    int pick = 1e9;
    if(nums[i]<=tar)
        pick = 1+dfs(nums,i,tar-nums[i]);
    return min(pick,notpick);
}
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    int ans = dfs(nums ,n-1 , x);
    if(ans>=1e9)
        return -1;
    else
        return ans;
}