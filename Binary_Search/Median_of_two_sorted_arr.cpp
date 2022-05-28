//naive--using merge sort TC(n+m) SC:O(n);

//optimal--using binary search
class Solution {
public:
       //binary search :Tc:O(min(n1,n2));
      // SC:O(1)
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
   
        if(nums2.size()<nums1.size()) //start with a smaller length array
            return findMedianSortedArrays(nums2,nums1);
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        int low=0 , high=n1;
        int left1 , left2 , right1 , right2;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            if(cut1==0)
                 left1=INT_MIN;
            else
                 left1=nums1[cut1-1];
            
            if(cut2==0)
                 left2=INT_MIN;
            else
                left2=nums2[cut2-1];
            
            if(cut1==n1)
                right1=INT_MAX;
            else
                right1=nums1[cut1];
            
            if(cut2==n2)
                right2=INT_MAX;
            else
                 right2=nums2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else
                    return max(left1,left2);
            }
            
            else if(left1>right2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        
        return 0.0;
    }
};