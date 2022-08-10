int dfs(int i , int j , vector<int>&nums)
{
    if(i==j)
        return 0;
    
    int mini=1e9;
    for(int k=i ;k<j ;k++)
    {
        int steps = nums[i-1]*nums[k]*nums[j]+dfs(i,k,nums)+dfs(k+1,j,nums);
        if(steps<mini)
            mini=steps;
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    return dfs(1,n-1,arr);
}