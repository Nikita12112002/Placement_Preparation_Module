class Solution {
public:
    
    int area(vector<vector<int>>&grid , int i , int j , int n , int m , int& count)
    {
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        
        if(grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
       if(area(grid,i-1,j,n,m,count)==1)
           count++;
       
        if(area(grid,i+1,j,n,m,count)==1)
            count++;
        
        if(area(grid,i,j-1,n,m,count)==1)
            count++;
        
        if(area(grid,i,j+1,n,m,count)==1)
            count++;
        
        return 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n= grid.size();
        int m=grid[0].size();
        int maxi=0 , count=0;
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<m ;j++)
            {
                
                if(grid[i][j]==1)
                {
                    count=1;
                    area(grid,i,j,n,m,count);
                    maxi= max(maxi ,count);
                }
            }
        }
        return maxi;
    }
};