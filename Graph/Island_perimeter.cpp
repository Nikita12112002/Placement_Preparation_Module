class Solution {
public:
    int p=0;
    void dfs(int i,int j , vector<vector<int>>&grid )
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        {
            p++;// counting boundary of those cells whose boundary is either out of bound or is a water cell
            return ;
        }
        
        if(grid[i][j]==0)
        {
            p++;
            return;
        }
        if(grid[i][j]==-1)
            return ;
      
        grid[i][j]=-1;
        
        
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
       return ;     
    }
    int islandPerimeter(vector<vector<int>>& grid) {
       
        for(int i=0 ;i<grid.size();i++)
        {
            for(int j=0 ;j<grid[0].size() ;j++)
            {
                if(grid[i][j]==1)
                  dfs(i,j,grid);
              
            }
        }
        return p;
    }
};