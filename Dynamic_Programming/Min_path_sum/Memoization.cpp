#include<bits/stdc++.h>
int dfs( int i , int j,vector<vector<int>>&grid ,vector<vector<int>>&dp)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return 1e9;
    if(dp[i][j]!=-1)
        return dp[i][j];
     int left = grid[i][j]+dfs(i-1,j,grid,dp);
    int right = grid[i][j]+dfs(i,j-1,grid,dp);
    return dp[i][j]=min(left,right);
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
    return dfs(n-1,m-1,grid,dp);
}

