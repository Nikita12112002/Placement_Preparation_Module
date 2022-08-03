class Solution {
public:
    int dfs(string s1 , string s2 , int i , int j)
    {
        if(i<0 || j<0)
            return 0;
        if(s1[i]==s2[j])
            return 1+dfs(s1,s2,i-1,j-1);
       
        return max(dfs(s1,s2,i,j-1) , dfs(s1,s2,i-1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();
        
        return dfs(text1 , text2 ,n-1,m-1);
    }
};