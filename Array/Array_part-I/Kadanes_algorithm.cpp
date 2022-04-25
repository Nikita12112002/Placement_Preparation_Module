#include<bits/stdc++.h>
long long maxSubarraySum(int arr[], int n) 
{
	// Write Your Code here   
	//Maximum Subaaray sum -Kadane's algorithm
	long long int sum=0, maxi=INT_MIN;
	
	for(long long int i=0;i<n;i++)
	{
		sum=sum+arr[i];
		if(sum>maxi)
			maxi=sum;
		if(sum<0)
			sum=0;
	}
	return maxi;
}
