 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        
        int n = nums.size();
       
        int i,j,low,high;
        for( i=0 ;i<n-3;i++)
        {
            if(i==0 || (i>0 && (nums[i]!=nums[i-1])))
            {     
            for(j=i+1;j<n-2;j++)
            {
               
             if(j==i+1 || (j>i+1&&(nums[j]!=nums[j-1])))
              {
                 low=j+1,high=n-1;
                 int sum = target-(nums[i]+nums[j]);
                 
                while(low<high)
                {
                    if(nums[low]+nums[high]==sum)
                    {
                          ans.push_back(vector<int>{nums[i],nums[j],nums[low],nums[high]});
                          
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    
                   else if(nums[low]+nums[high]<sum) low++;
                    
                    else
                        high--;
                }
              }
            }
            }
        }
        return ans;
    }