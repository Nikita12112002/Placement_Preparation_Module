class Solution {
public:
    int dfs(int i , int j , vector<int>&nums)
    {
        if(i>j)
            return 0;
        
        int  maxi = -1e9;
        
        for(int ind=i ; ind<=j ; ind++)
        {
            int cost = nums[i-1]*nums[ind]*nums[j+1] + dfs(i,ind-1,nums)+dfs(ind+1,j,nums);
            
            maxi = max(maxi,cost);
            
            
        }
        
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        
         int n = nums.size();
         nums.push_back(1);
         nums.insert(nums.begin(),1);
        return dfs(1,n,nums);
    }
};