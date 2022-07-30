int maximum(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

 
  //Outer Nested Loops for travering DP Array
  for (int i = n - 1; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {
          
          if(i==n-1)
          {
              if (j1 == j2)
                 dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                  dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
              continue;
          }

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // 3-D dp
    // declaring a 3D dp vector
    return maximum(r, c, grid);
    
}