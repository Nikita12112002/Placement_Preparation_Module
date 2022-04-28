// First step to ask whther the n can be negative also 

double myPow(double x, int n) {
        
        //Time complexity is O(n) and space complexity is O(1).This solution will give time limit exceeded.
        
        
        double ans=1;
        int i;
        
        for(i=0 ; i<abs(n) ; i++)
        {
            ans = ans*x;
        }
        
        if(n<0)   // if n is negative.
        {
            ans = 1/ans;
        }
        return ans;
        
    }
