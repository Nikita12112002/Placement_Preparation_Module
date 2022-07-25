int f(int n , vector<int>&nums ,vector<int>&dp)
{
    if(n==0)
        return nums[0];
    if(n==1)
        return max(nums[0],nums[1]);
    if(dp[n]!=-1)
        return dp[n];
    int pick = nums[n]+f(n-2,nums,dp);
    int nonpick = f(n-1,nums,dp);
    return dp[n]=max(pick,nonpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n+1,-1);
	return f(n-1,nums,dp);
}