//TC : O(n) , SC:O(n)

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
	unordered_map<int,int>m;
	int xr=0,count=0;
	for(int i=0 ;i<arr.size() ;i++)
	{
		xr = xr ^ arr[i];
		
		if(xr==x)
			count++;
		
		if(m.find(xr^x)!=m.end())
			count=count+m[xr^x];
		
		m[xr]++;
	}
	return count;
}