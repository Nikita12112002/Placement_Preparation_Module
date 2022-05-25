// brute force -- iterate every element and put it in a new data structure
// sort the data structure and find the median
// TC : n*m for putting all the ele in data structure and for sorting n*m logn(n*m)
// SC:O(n*m)

// optimal approach--> using binary search

int func(vector<int>&A  ,int mid)
{
    int low=0 , high=A.size()-1;
    
    while(low<=high)
    {
        int md=(low+high)/2;
        
        if(A[md]<=mid)
            low=md+1;
        else
            high=md-1;
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    
    int low=1 , high=1e9;
    int mid,count;
    int n=matrix.size();
    int m=matrix[0].size();
    while(low<=high)
    {
        mid=(low+high)/2;
        count=0;
        for(int i=0 ;i<n;i++)
            count=count+func(matrix[i],mid);
        
        if(count<=(n*m)/2)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}