// Approach 1- brute force- TC: O(n2) Sc:O(1)

int removeDuplicates(vector<int>& nums) {
        
      
        for(int i=1 ;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        
        return nums.size();
    }

//Approach 2- using hashmap TC:O(n) SC:O(n)

//Approach 3- two pointer TC:O(n) SC:O(1)

int removeDuplicates(vector<int>& nums) {
   
     int i=0, j;
        
        for(j=1 ;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
               
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
