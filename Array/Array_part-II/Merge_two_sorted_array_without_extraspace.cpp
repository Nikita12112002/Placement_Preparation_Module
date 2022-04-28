// Approach1 -- TC:O(n) , SC:O(1);
// Approach2 - TC: O(Nlogn) SC:O(1)----> gap method

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i1=m-1 ,i2=n-1 , j=m+n-1;
	
	while(i1>=0 && i2>=0)
	{
		if(arr1[i1]>arr2[i2])
		{
			arr1[j]=arr1[i1];
			i1--;
			j--;
		}
		else
		{
			arr1[j]=arr2[i2];
			i2--;
			j--;
		}
	}
	
	while(i2>=0)
	{
		    arr1[j]=arr2[i2];
			i2--;
			j--;
	}
	return arr1;
}




