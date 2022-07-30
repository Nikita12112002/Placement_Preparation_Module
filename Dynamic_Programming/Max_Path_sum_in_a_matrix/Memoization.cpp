int dfs( vector<vector<int>> &matrix, int i, int j, int m,
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + dfs(matrix,i-1,j,m,dp);
    int left = matrix[i][j] + dfs(matrix,i-1,j-1,m,dp);
    int right = matrix[i][j] + dfs(matrix,i-1,j+1,m,dp);
    
    return dp[i][j]= max(up,max(left,right));
 }
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int j=0 ;j<m ;j++)
    {
        maxi=max(maxi,(dfs(matrix,n-1,j,m,dp)));
    }
    return maxi;
    

}