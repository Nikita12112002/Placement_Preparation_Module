class Solution {
public:
    
    int f(int n)
    {
        if(n==0 || n==1)
            return 1;
        
        int prev1=1;
        int prev2=1;
        int curr;
        
        for(int i=2 ;i<=n ;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
    int climbStairs(int n) {
    
       if(n==0|| n==1)
           return 1;
        
       return f(n);
        
    }
};