class Solution {
public:
    int dfs(string &s , string &t , int i , int j , vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j] = 1+dfs(s,t,i-1,j-1,dp);
        return dp[i][j]=max(dfs(s,t,i-1,j,dp),dfs(s,t,i,j-1,dp));
    }
    int minInsertions(string s) {
        
        int n = s.length();
        int m =n;
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return n-dfs(s,t,n-1,m-1,dp);
        
    }
};