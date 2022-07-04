//TC:O(n) , SC:O(n)

class Solution {
public:
    int candy(vector<int>& rat) {
        
        int c=0;
        int n =rat.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
     
        for(int i= 1 ; i<n ; i++)
        {
            if(rat[i]>rat[i-1])
                left[i]=left[i]+left[i-1];
        }
        
        for(int i=n-2 ;i>=0 ;i--)
        {
            if(rat[i]>rat[i+1])
                right[i]=right[i+1]+1;
                
        }
        
        for(int i=0 ;i<n ;i++)
        {
            c=c+max(left[i],right[i]);
        }
        
        return c;
    }
};