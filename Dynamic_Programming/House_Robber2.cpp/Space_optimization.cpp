class Solution {
public:
  long long int f(long long int start , long long int high ,vector<int> &nums)
{
    long long int prev2=nums[start];
	long long int prev1=max(nums[start],nums[start+1]);
	long long int curr;
	if(start==high)
      return nums[start];
	if(high-start==1)
	
		return max(nums[start],nums[start+1]);
	
	for(long long int i=start+2 ; i<=high;i++)
	{
		curr=max((nums[i]+prev2),prev1);
		prev2=prev1;
		prev1=curr;
	}

   return prev1;
}

    int rob(vector<int>& nums) {
        
        int n =nums.size();
        
        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0],nums[1]);
       
      long long int ans1=f(0,n-2,nums);
 long long  int ans2=f(1,n-1,nums);
  
  return max(ans1,ans2);
    }
};