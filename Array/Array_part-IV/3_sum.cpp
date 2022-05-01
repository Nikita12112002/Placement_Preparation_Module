#include <bits/stdc++.h> 
//TC: O(n2)
vector<vector<int>> findTriplets(vector<int>nums, int n, int sum) {
	// Write your code here
	  
         int i=0;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        
        for(i=0 ;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int low=i+1 ;
                int high=n-1;
                int target=sum-nums[i];
                
                while(low<high)
                {
                    if(nums[low]+nums[high]==target)
                    {
                        vector<int>res;
                        res.push_back(nums[i]);
                        res.push_back(nums[low]);
                        res.push_back(nums[high]);
                        ans.push_back(res);
                        
                        while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    low++;
                    high--;
                    }
                    
                    if(nums[low]+nums[high]<target)
                        low++;
                    if(nums[low]+nums[high]>target)
                        high--;
                   
                }
            }

        }
        return ans;
    
}