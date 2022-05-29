// naive approach -->linear search 
// TC:O(n) SC:O(1)

//optimal --> binary search
// note- if we are standing at a point either the left half or right half has to be sorted.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0 , high=nums.size()-1;
        
        while(low<=high)
        {
            int mid= (low+high)/2; 
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[low]<=nums[mid]) // left part is sorted
            {
                //check wheather target belongs to left part
                if(target>=nums[low] && target<=nums[mid]) 
                    high=mid-1;
                
                else
                    low=mid+1; // means left part is sorted but target doesnot belong to left part
            }
            // left part is unsorted it means right part will defintely be sorted so we update low;
            else
            {
                //check the target in the right part
                if(target>=nums[mid] && target<=nums[high]) 
                    low=mid+1;
                else
                    high=mid-1;
            }
            
        }
       return -1; 
    }
};