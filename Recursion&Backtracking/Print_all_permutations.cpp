class Solution {
public:
    
    // intution --> we want each value at every index.
    //ex- 1,2,3 --> we want 1 at index 0,1,2;
    // also we want 2 at every pos ie - 0 ,1,2;
    //same goes for three as well.
    
    void solve(vector<int>&nums , vector<vector<int>>&ans , int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        // loop for taking one index and swaping it with every other value in an array
        
        for(int i=index ; i<nums.size();i++)
        {
        // swap the index and i values to get a new permutation
          swap(nums[index],nums[i]) ;
        // every time pointer will increment by 1
          solve(nums,ans,index+1);
        // restore the swaps , because it will not work for other iterations
          swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
        
    }
};