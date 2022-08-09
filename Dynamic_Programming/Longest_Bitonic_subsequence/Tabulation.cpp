int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	 
    vector<int>dp1(n,1);
    vector<int>dp2(n,1);
    
    for(int i=0 ;i<n ;i++)
    {
        for(int prev=0 ; prev<i; prev++)
        {
            if(arr[i]>arr[prev] && 1+dp1[prev]>dp1[i])
               dp1[i]=1+dp1[prev];
        }
    }
     for(int i=n-1 ;i>=0 ;i--)
    {
        for(int prev=n-1 ; prev>i ;prev--)
        {
            if(arr[i]>arr[prev] && 1+dp2[prev]>dp2[i])
               dp2[i]=1+dp2[prev];
        }
    }
    
   int ans=-1;
    for(int i=0;i<n;i++){
        int x=dp1[i]+dp2[i]-1;
        ans=max(ans,x);
    }
    return ans;
} 
