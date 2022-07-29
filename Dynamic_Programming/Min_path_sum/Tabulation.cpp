#include<bits/stdc++.h>
int dfs(vector<vector<int>>grid , int n , int m,vector<vector<int>>&dp)
{
  
    for(int i=0 ;i<grid.size() ;i++)
    {
        for(int j=0 ;j<grid[0].size() ;j++)
        {
          if(i==0 && j==0) 
              dp[i][j] = grid[0][0];
           
            else{
                
               int up=0,left=0;
                if(i>0) 
                     up = grid[i][j]+dp[i-1][j];
                else 
                   up = grid[i][j]+1e9;
                
               
                if(j>0) 
                     left= grid[i][j]+dp[i][j-1];
                else
                  left= grid[i][j]+1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
   return dp[n-1][m-1];
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return dfs(grid,n,m,dp);
}

