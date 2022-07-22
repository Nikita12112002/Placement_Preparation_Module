// recursive sol ---tle

class Solution {
public:
    bool dfs(vector<int>nums , int n , int i)
    {
        if(i==n-1)
            return true;
        
        int val = nums[i];
        for(int j=i+1 ;j<=i+val ;j++)
        {
            if(dfs(nums,n,j))
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
    
      if(nums.size()==1)
          return true;
      if(dfs(nums,nums.size(),0))
          return true;
        return false;
    }
};

