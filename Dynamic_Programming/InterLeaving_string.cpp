class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
       // recursive --> will give Tle
        
        if(s3.size()!=s1.size()+s2.size())return false;
        return solve(s1,s2,s3,0,0);
    }
        
        bool solve(string s1,string s2,string s3,int i , int j)
    {
        
        if(i==s1.length() && j==s2.length())
            return true;
        
        if(i<s1.length() && s1[i]==s3[i+j])
        {
            bool f1= solve(s1,s2,s3,i+1,j);
            
            if(f1==true)
                return true;

        }
        
        if(j<s2.length() && s2[j]==s3[i+j])
        {
            bool f2= solve(s1,s2,s3,i,j+1);
            
            if(f2==true)
                return true;

        }
       return false; 
        
        
// Tabulation approach

        
      int n=s1.length();
        int m=s2.length();
        
        if(n+m!=s3.length())
            return 0;
        
        bool dp[n+1][m+1];
        
                memset(dp,0,sizeof(dp));
        

        
      for(int i=0; i<n+1; i++)
      {
        for(int j=0; j<m+1; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = true;
            
            else if(i == 0)
            {
                if(s2[j-1]== s3[i+j-1])
            
                    dp[i][j] =  dp[i][j-1] ;
                   
                   else
                     dp[i][j]=false;
            }
            else if(j == 0)
            {
                if(s1[i-1] == s3[i+j-1])
                  dp[i][j] = dp[i-1][j];
                
                else
                    dp[i][j]=false;
            }
            else
            {
                
                
                if(s1[i-1] == s3[i+j-1])
                 dp[i][j] = dp[i-1][j] ;
                
                if(s2[j-1] == s3[i+j-1])
                dp[i][j] =  dp[i][j] || dp[i][j-1];
            }
                
                 
            
        }
          
      }
      return dp[n][m];  
    }
};