//brute force --> TC:O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      //brute force sol -- using xor   
        int ans=nums[0];
        
        for(int i=1 ;i<nums.size() ;i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
};

// optimal --using binary search -->TC:O(logn)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      //note--
      //right half--> 1st instance-odd index
      //               2nd instance--even index
        
       //left half--> 1st instance-->even index
       //             2nd instance-->odd index
        int low=0 ,high=nums.size()-2;
        
        while(low<=high)
        {
           int mid=(low+high)/2;
            
        // note- xor of even index with 1 always gives odd index
        // and xor of odd index with 1 always give even index
            
            if(nums[mid]==nums[mid^1]) // signifies we are on the left half
            // mid^1 is going to give previous even or next odd
                low=mid+1;
            else
                high=mid-1;
        }
        return nums[low];
        
    }
};
