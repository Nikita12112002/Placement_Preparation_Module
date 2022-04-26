 void nextPermutation(vector<int>& nums) {
        
        // Check from last which number is first smaller number.
        // ur k will point to that index now;
        // now if k is less than 0 it means smaller number we find is at position k
        
        // so we directly reverse the array.
        
        // and if k >0 then check which first no from last is greater than k .
        //swap that no if kth no.
        // then reverse the array from k+1 to last;
        int n=nums.size(),k,i;
        for( k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }
        
        if(k<0)
            reverse(nums.begin(),nums.end());
        
        else
        {
            for( i=n-1 ; i>k ;i--)
            {
                if(nums[i]>nums[k])
                    break;
            }
            
             swap(nums[k],nums[i]);
        reverse(nums.begin()+k+1,nums.end());
        }
        
       
        
    }