class Solution {
public:
    
    void count_Islands(vector<vector<char>>&grid , int i , int j , int n , int m )
    {
        if(i<0||j<0||i>=n||j>=m)
            return ;
        if(grid[i][j]=='0')
            return ;
        
        grid[i][j]='0';
        
         count_Islands(grid,i-1,j,n,m);
         count_Islands(grid,i+1,j,n,m);
         count_Islands(grid,i,j-1,n,m);
         count_Islands(grid,i,j+1,n,m);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<m ;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    count_Islands(grid,i,j,n,m);
                }       
                
            }
        }
        
        return count;
    }
};