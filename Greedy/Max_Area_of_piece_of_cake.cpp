class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        sort(horizontalCuts.begin() , horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        long long  p,q;
        
            p=max(horizontalCuts[0],h-horizontalCuts[n-1]);
       
         for(int i=1 ;i<n ;i++)
         {
            long long a= (long)horizontalCuts[i]-horizontalCuts[i-1];
             p=max(p,a );
         }
           
       
            q= max(verticalCuts[0] , w-verticalCuts[m-1]);
        
      for(int i=1 ;i<m ;i++)
      {
          long long b=(long)verticalCuts[i]-verticalCuts[i-1];
          q=max(q,b );
      }
           
          return (int)((long)p * q % 1000000007);
        
       
        
    }
};