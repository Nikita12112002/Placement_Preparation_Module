int dfs(vector<vector<int>>matrix , int i , int j , int col)
{
     if(j<0 || j>=col)
        return -1e9;
    if(i==0)
        return matrix[i][j];
   
    int up = matrix[i][j]+dfs(matrix,i-1,j,col);
    int left = matrix[i][j]+dfs(matrix,i-1,j-1,col);
    int right = matrix[i][j]+dfs(matrix,i-1,j+1,col);
    
    return max(up,max(left,right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    for(int j=0 ;j<m ;j++)
    {
        maxi=max(maxi,(dfs(matrix,n-1,j,m)));
    }
    return maxi;
}