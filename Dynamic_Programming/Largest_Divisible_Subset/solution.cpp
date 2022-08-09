class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        long n = nums.size();
        vector<long long>hash(n,1);
        vector<long long>dp(n,1);
        sort(nums.begin(),nums.end());
        for(long i=0 ; i<n ;i++)
        {
            hash[i]=i;
            for(long prev=0 ; prev<i ; prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        
        long  maxi=-1 , maxi_ind=-1;
        for(int i=0 ;i<n ;i++)
        {
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                maxi_ind=i;
            }
        }
        
        vector<int>ans;
        ans.push_back(nums[maxi_ind]);
        
        while(hash[maxi_ind]!=maxi_ind)
        {
            maxi_ind=hash[maxi_ind];
            ans.push_back(nums[maxi_ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};