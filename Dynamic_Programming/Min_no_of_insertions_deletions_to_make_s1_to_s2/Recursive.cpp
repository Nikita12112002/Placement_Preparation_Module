  int dfs(string s1 , string s2 , int i , int j)
    {
        if(i<0 || j<0)
            return 0;
        if(s1[i]==s2[j])
            return 1+dfs(s1,s2,i-1,j-1);
       
        return max(dfs(s1,s2,i,j-1) , dfs(s1,s2,i-1,j));
    }
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    int lcs = dfs(str,ptr,n-1,m-1);
    
    int ans = (n-lcs)+(m-lcs);
}