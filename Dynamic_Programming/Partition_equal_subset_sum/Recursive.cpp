//s1=s2=s/2;
// note - odd sum of an array can never be divided into two equal subset
// question boils down -->
// find out one subset whose sum is equal to half of the total sum
// then the remaining elements are bound to give the sum equal to the sum of half of arr
// so the problem reduces to the sum of subset equal to target. 

bool dfs(vector<int>&a , int i , int target)
{
    if(target==0)
        return true;
    if(i==0)
    {
        if(a[i]==target)
            return true;
        return false;
    }
   bool nonpick = dfs(a,i-1,target);
    bool pick =false;
    if(a[i]<=target)
    pick = dfs(a,i-1,target-a[i]);
    
    return pick||nonpick;
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int sum=0;
    for(int i=0 ;i<arr.size() ;i++)
    {
        sum=sum+arr[i];
    }
    
    if(sum%2!=0)
        return false;
    if(dfs(arr,n-1,sum/2))
        return true;
    return false;
}
