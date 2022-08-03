  int dfs(string &s1 , string &s2 , int i , int j , vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+dfs(s1,s2,i-1,j-1,dp);
       
        return dp[i][j]=max(dfs(s1,s2,i,j-1,dp) , dfs(s1,s2,i-1,j,dp));
    }
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    
    vector<vector<int>>dp(n,vector<int>(m+1,-1));
    int lcs = dfs(str,ptr,n-1,m-1,dp);
    
     return (n-lcs)+(m-lcs);
}