class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
 long long merge(long long arr[], long long temp[] ,long long left ,long long mid, long long right)
{
    long long inv_count=0;
    long long i = left;
     long long j = mid;
    long long k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

long long merge_Sort(long long arr[],long long temp[],long long left,long long right)
{
    long long mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
         long long temp[n];
    long long ans = merge_Sort(arr,temp,0,n-1);
      return ans;  
        
    }

};