class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n = nums.size(),sum_e=0 ,sum_o=0;
        vector<int>even(n,0);
        vector<int>odd(n,0);
        
        even[0]=nums[0];
        
        for(int i=1 ;i<nums.size();i++)
        {
            if(i%2==0)
            {
                even[i]=nums[i]+even[i-1];
                odd[i]=odd[i-1];
            }
            else
            {
                odd[i]=nums[i]+odd[i-1];
                even[i]=even[i-1];
            }
                
        }
        
        int ans=0;
        
        for(int i=0 ;i<nums.size();i++)
        {
            int prefix_even_sum=0 , suffix_even_sum=0;
            int prefix_odd_sum=0 , suffix_odd_sum=0;
            int even_total=0 , odd_total=0;
            
            if(i==0)
            {
            prefix_even_sum=0;
            prefix_odd_sum=0;
            }
            
            else
            {
                prefix_even_sum=even[i-1];
                prefix_odd_sum=odd[i-1];
            }
            
            if(i==n-1)
            {
            suffix_even_sum=0;
            suffix_odd_sum=0;
            }
            
            else
            {
                suffix_even_sum=odd[n-1]-odd[i];
                suffix_odd_sum=even[n-1]-even[i];
            }
                
            
           even_total= prefix_even_sum + suffix_even_sum;
           odd_total = prefix_odd_sum + suffix_odd_sum;
            
            if(even_total == odd_total)
                ans++;
            
        }
            
        return ans;    
        
    }
};