int dfs(int i , int wt , vector<int>&profit , vector<int>&nums)
{
    if(i==0)
    {
        
            return ((int)wt/nums[0])*profit[i];
       
    }
    int notpick = dfs(i-1,wt,profit,nums);
    int pick=-1e9;
    if(nums[i]<=wt)
        pick = profit[i]+dfs(i,wt-nums[i],profit,nums);
    
    return max(notpick,pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return dfs(n-1,w,profit,weight);
    
}
