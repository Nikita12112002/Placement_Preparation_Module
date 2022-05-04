// Approach 1-Brute force - TC:O(n2)
//for every i take out left max height of building and right max 
// find the min of left max and right max
// amount of water stored at index i = min - a[i];

// Approach 2- TC:O(n) SC:O(2n)
// using prefix left array anf perfix right array 
// and then follow the formula min(left[i],right[i]-a[i]);

//Approach 3- Two pointer
 int trap(vector<int>& height) {
        
        int n=height.size();
        int left=0 , right=n-1 ,leftmax=0 ,rightmax=0,res=0;
        
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=leftmax)
                {
                    leftmax=height[left];
                }
                else
                {
                    res=res+(leftmax-height[left]);
                }
                left++;
            }
            
            else
            {
                if(height[right]>=rightmax)
                    rightmax=height[right];
                else
                    res=res+(rightmax-height[right]);
                    
                    right--;
            }
        }
        return res;
    }