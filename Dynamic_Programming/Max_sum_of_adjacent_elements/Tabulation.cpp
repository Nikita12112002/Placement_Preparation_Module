int f(int n , vector<int>&nums ,vector<int>&dp)
{
    if(n==0)
        return nums[0];
    if(n==1)
        return max(nums[0],nums[1]);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    
   for(int i=2 ;i<=n ;i++)
   {
    int pick = nums[i]+dp[i-2];
    int nonpick = dp[i-1];
    dp[i]=max(pick,nonpick);
   }
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n+1,-1);
	return f(n-1,nums,dp);
}