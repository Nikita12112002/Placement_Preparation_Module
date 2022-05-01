#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
	unordered_map<int,int>m;
	int n = arr.size() , sum=0 ,maxi=0,length;
	for(int i=0 ;i<n ;i++)
	{
		sum= sum+arr[i];
		if(sum==0)
			maxi=i+1;
		if(m.find(sum)==m.end())
		    m[sum]=i;
		else
			maxi =max(maxi,i-m[sum]);
		
		
	}
return maxi;
}