  int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count=0 ,maxi=0;
        for(int i=0 ;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                maxi=max(maxi,count);
                count=0;
            }
        }
        return max(maxi,count); // case - 1 1 0 1 1 1 
    }