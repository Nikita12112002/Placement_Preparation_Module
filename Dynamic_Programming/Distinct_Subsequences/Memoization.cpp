class Solution {
public:
    int dfs(string &s , string &t , int i , int j , vector<vector<int>>&dp)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
            return dp[i][j]=dfs(s,t,i-1,j-1,dp)+dfs(s,t,i-1,j,dp);
       
            return dp[i][j]=dfs(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        
        int n= s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return dfs(s,t,n-1,m-1,dp);
        
    }
};