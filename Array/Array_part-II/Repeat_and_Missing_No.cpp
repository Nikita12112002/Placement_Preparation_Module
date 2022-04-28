//TC:O(n) SC:O(1)

pair<int,int> missingAndRepeating(vector<int> &A, int n)
{
	// Write your code here 
	pair<int,int>p;
	
	for(int i=0 ;i<n ;i++)
    {
        while(A[i]>0 && A[i]<=n && A[A[i]-1]!=A[i])
        {
            swap(A[i],A[A[i]-1]);
        }
    }
        
        for(int i=0 ;i<n ;i++)
        {
            if(A[i]!=i+1)
            {
                p.first=i+1;
				p.second=A[i];
			}
        }
        return p;
}
