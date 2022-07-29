#include<bits/stdc++.h>
int dfs(vector<vector<int>>grid , int i , int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return 1e9;
    if(dp[i][j]!=-1)
        return dp[i][j];
     int left = grid[i][j]+dfs(grid,i-1,j,dp);
    int right = grid[i][j]+dfs(grid,i,j-1,dp);
    return min(left,right);
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
   
    int n = grid.size();
    int m = grid[0].size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
    return dfs(grid,n-1,m-1,dp);
}

