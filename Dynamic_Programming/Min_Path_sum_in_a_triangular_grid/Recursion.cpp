int f(vector<vector<int>>& grid ,int i, int j , int n)
{
    if(i==n-1)
        return grid[n-1][j];
    int down= grid[i][j] + f(grid,i+1,j,n);
    int dia = grid[i][j] + f(grid,i+1,j+1,n);
    
    return min(down,dia);
    
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return f(triangle,0,0,n);
}