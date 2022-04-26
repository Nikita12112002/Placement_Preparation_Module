//brute-force-> sort the array using sort function. TC:nlogn

//optimizedsol->counting sort -  non-comparison based sorting algorithm. TC: O(2n)
// counting sort will do this in 2 passes first n passes for the counting and another
// n passes for filling

//Most optimized-> DUTCH NATIONAL FLAG ALGORITHM (below implementation): TC:O(n), SC:O(1)

// DUTCH NATIONAL FLAG ALGORITHM 
// 1. take three pointers , low , mid and high.
// 2. low=0 , mid=0 , high=n-1;
// 3. This algorithm is based on the fact that all the numbers from 0 to low-1 are zeros
// 4. and all the elements from high+1 to n are 2.
// 5. and all the elements between low to mid-1 are 1
// 6. we will move mid pointer until and unless it crosses the high pointer

//while moving we have three checks-> mid==0 or mid==1 or mid==2

// conditions->
//  1. mid==0 then swap a[low] and a[mid]
//  2.increment low and mid by 1
//  3. mid==1 then move the mid pointer without doing anything
//  4. mid==2 then swap a[mid] and a[high] and decrement high


   void sortColors(vector<int>& arr) {
        int low=0 ,high=arr.size()-1 , mid=0;
	
	for(int i=0 ;i<arr.size();i++)
	{
		if(arr[mid]==0)
		{
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		
		else if(arr[mid]==1)
			mid++;
		
		else
		{
			swap(arr[mid],arr[high]);
			high--;
		}
		
			
	}
        
    }