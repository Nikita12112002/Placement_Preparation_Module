int f(int i , int j , vector<vector<int>>mat)
{
    if(i==0 && j==0)
        return 1;
    if(i<0 || j<0)
        return 0;
    if(i>=0 && j>=0 && mat[i][j]==-1)
        return 0;
   return f(i-1,j,mat)+f(i,j-1,mat);
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    
    return f(n-1,m-1,mat);
}