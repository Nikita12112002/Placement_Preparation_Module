int f(int n , vector<int>&nums)
{
    if(n==0)
        return nums[0];
    if(n==1)
        return max(nums[0],nums[1]);
    int prev1=nums[0];
    int prev2=max(nums[0],nums[1]);
    int curr;
   for(int i=2 ;i<=n ;i++)
   {
    int pick = nums[i]+prev1;
    int nonpick = prev2;
    curr=max(pick,nonpick);
     prev1=prev2;
     prev2=curr;
   }
    return curr;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
   
	return f(n-1,nums);
}