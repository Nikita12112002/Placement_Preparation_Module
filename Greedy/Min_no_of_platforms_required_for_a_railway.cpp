 int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int j=0,platforms=1,maxi=platforms,i=1;
    	
        while(i<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        platforms++;
    	        i++;
    	    }
    	    
    	    else
    	    {
    	     platforms--;
    	     j++;
    	    }
    	     
    	     maxi=max(maxi,platforms);
    	}
    	
    	return maxi;
    }