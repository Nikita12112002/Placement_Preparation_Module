class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
       int c1=1 ,c2=1;
    
        if(nums.size()==1)
            return 1;
        else if(nums.size()==2 && nums[0]!=nums[1])
            return 2;
        
        for(int i=1 ;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
             c1= c2+1;
            
            else if(nums[i]<nums[i-1])
                c2=c1+1;
            
        }
        return max(c1,c2);
    }
};