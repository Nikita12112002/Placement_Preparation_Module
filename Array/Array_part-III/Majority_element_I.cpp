   // Moores Voting Algorithm TC:O(n) SC:O(1)
    int majorityElement(vector<int>& nums) {
        
        int count=0 , ele=0;
        
        for(int i=0 ;i<nums.size();i++)
        {
            if(count==0)
                ele=nums[i];
            
            if(ele==nums[i])
                count++;
            
            else
                count--;
        }
         count=0;
        // below code is just to check wheather the element stored in element is majority, if not then majority does not exist.
        
        // This is the extra part if questions says majority may or may not exist, here in this question it is defined that majority will definiely exist so we can skip this part od code.
        for(int i=0 ;i<nums.size() ;i++)
        {
            if(nums[i]==ele)
                count++;
                
        }
        if(count>nums.size()/2)
        return ele;
        
        return 0;
    }