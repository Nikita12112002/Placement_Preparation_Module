class Solution {
public:
    int dfs(string &s , string &t , int i , int j)
    {
        if(i<0 || j<0)
            return 0;
        if(s[i]==t[j])
            return 1+dfs(s,t,i-1,j-1);
        return max(dfs(s,t,i-1,j) , dfs(s,t,i,j-1));
    }
    int longestPalindromeSubseq(string s) {
        
        string t=s;
        reverse(t.begin(),t.end());
        
        int n = s.size();
        int m=n;
        return dfs(s,t,n-1,m-1);
        
    }
};