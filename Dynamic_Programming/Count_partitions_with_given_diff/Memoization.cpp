int mod=(int)1e9+7;
int dfs(vector<int>&arr , int ind , int target , vector<vector<int>>&dp)
{
   if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
  int notTaken = dfs(arr,ind-1,target,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = dfs(arr,ind-1,target-arr[ind],dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total =0;
    for(int i=0 ; i<n ;i++)
    {
        total = total + arr[i];
    }
    
    
    if(total-d<0 || (total-d)%2!=0)
        return 0;
    int tar = (total-d)/2;
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return dfs(arr,n-1,tar,dp);
    
}


