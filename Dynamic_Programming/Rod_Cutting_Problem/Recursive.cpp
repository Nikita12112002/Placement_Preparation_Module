int dfs(vector<int>&price , int i , int tar)
{
    if(i==0)
    {
        // since the rod at 0 ind is of length 1
        return tar*price[0];
    }
    int notpick = dfs(price , i-1 , tar);
    int pick = -1e9;
    int rodlen = i+1;
    if(rodlen<=tar)
        pick = price[i]+dfs(price , i , tar-rodlen);
    return max(notpick , pick);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return dfs(price,n-1,n);
}
