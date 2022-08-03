#include<bits/stdc++.h>
int solve(string &str1, string &str2, int i,int j,int &count , vector<vector<int>>&dp)
{
    if(i<0||j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int take=0;
    if(str1[i]==str2[j])
    {
        take=1+solve(str1,str2,i-1,j-1,count,dp);
    }
    int a=solve(str1,str2,i-1,j,count,dp);
   int b=solve(str1,str2,i,j-1,count,dp);
    count=max(count,take);
    
    return dp[i][j]=take;
}
int lcs(string &str1, string &str2){
    int n=str1.size();
    int m=str2.size();
    int count=0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      solve(str1,str2,n-1,m-1,count,dp);
    
    return count;
}