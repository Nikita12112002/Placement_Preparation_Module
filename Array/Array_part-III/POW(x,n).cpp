// POW(X,N) also known as Modular exponentiation

// First step to ask wheather the n can be negative also 

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

    //optimal approach  -- TC:O(logn)
   double myPow(double x, int n) {
        
        // time complexity of this approach is log base 2 n , because n is getting divided by half .
        
        
       double ans =1;
       long long copy=n;
        
        if(copy<0)
        {
            copy= -1 * copy;             // making a number positive.
        }
        
        while(copy>0)
        {
            if(copy%2 !=0)                       //if odd.
            {
                ans = ans*x;
                copy=copy-1;
            }
            
            else{                                // even
                
                x= x*x;
                copy=copy/2;
            }
        }
        
        if(n<0)
        {
            ans= double(1.0)/(double)(ans);   // if number is negative
        }
        
        return ans;
        
    }