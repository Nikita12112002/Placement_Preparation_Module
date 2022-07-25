int f(int n , vector<int>&nums)
{
    if(n==0)
        return nums[0];
    if(n==1)
        return max(nums[0],nums[1]);
    int pick = nums[n]+f(n-2,nums);
    int nonpick = f(n-1,nums);
    return max(pick,nonpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
	return f(n-1,nums);
}