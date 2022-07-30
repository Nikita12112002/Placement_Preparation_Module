int dfs(int i , int j1 , int j2 , int r  , int c , vector<vector<int>>grid)
{
    if(j1<0 || j1>=c || j2<0 || j2>=c)
        return -1e9;
    if(i==r-1)
    {
        if(j1==j2)
          return grid[i][j1];
        else
            return grid[i][j1]+grid[i][j2];
    }
    
    int maxi = -1e9;
    for(int dj1=-1 ; dj1<=1 ; dj1++)
    {
        for(int dj2=-1 ; dj2<=1 ; dj2++)
        {
            int value=0;
            if(j1==j2)
                value=grid[i][j1];
            else
                value=grid[i][j1]+grid[i][j2];
            
            value = value + dfs(i+1 , j1+dj1 , j2+dj2 , r ,c , grid);
            maxi=max(maxi ,value);
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // 3-D dp
    
    return dfs(0,0,c-1,r,c,grid);
    
}