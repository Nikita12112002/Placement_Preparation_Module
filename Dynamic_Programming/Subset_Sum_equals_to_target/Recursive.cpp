bool dfs(vector<int>&a , int i , int k )
{
   if(k==0)
       return true;
    if(i==0)
    {
        if(a[i]==k)
            return true;
        return false;
    }
        
    
    return dfs(a,i-1,k) || dfs(a,i-1,k-a[i]);
}
bool subsetSumToK(int n, int k, vector<int> &arr ) {
    // Write your code here.
 
     if(dfs(arr,n-1,k))
         return true;
    return false;
}