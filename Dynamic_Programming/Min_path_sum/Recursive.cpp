#include<bits/stdc++.h>
int dfs(vector<vector<int>>grid , int i , int j)
{
    if(i==0 && j==0)
        return grid[0][0];
    if(i<0 || j<0)
        return 1e9;
     int left = grid[i][j]+dfs(grid,i-1,j);
    int right = grid[i][j]+dfs(grid,i,j-1);
    return min(left,right);
    
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    return dfs(grid,n-1,m-1);
}

