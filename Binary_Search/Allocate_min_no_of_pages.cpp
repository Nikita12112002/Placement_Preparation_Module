class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocationPossible(int arr[],int barrier,int k,int n)
    {
        int allocatedStudents=1;   //STUDENTS ALLOCATED INITIALLY TAKE AS 1 STUDENT
        int pages=0;                // PAGE SUM 
        
        for(int i=0;i<n;i++)
        {       //practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
            if(arr[i]>barrier)      //CHECK WHETHER THE FIRST BOOK CAN EVEN BE ASSIGNED OR NOT
                return false;
                
            if(arr[i]+pages>barrier)
            {       ////CHECK WHETHER THESE MANY BOOKS ASSIGNED COMES UNDER THE BARRIER OR NOT IF NOT THEN ASSIGN BOOKS TO NEW STUDENT
                allocatedStudents++;
                pages=arr[i];           //RESET THE NUMBERING FROM THE CURRENT BOOK
            }
            
            else
            {
                pages+=arr[i];          //NO ISSUES JUST KEEP ON ADDING THE BOOKS
            }
        }
        if(allocatedStudents<=k)    
            return true; 
            
        return false;                    
    }
    
    int findPages(int arr[], int n, int k) 
    {
        if(k>n)                 //CHECK WHETHER K>N THEN RETURN -1
            return -1;
          
    //   sort(arr,arr+n);
        
        
    //     for(int i=0 ;i<n ;i++)
    //     {
    //         sum=sum+arr[i];
    //     }
        int lo=arr[0];
        int hi=0;
        int res=-1;
        for(int i=0;i<n;i++) //ASSIGN THE MINIMUM POSSIBLE VALUE TO LO AND SUM OF THE ARRAY TO HI
        {       
            
            hi+=arr[i];             // either sort the array and assign min value to low and sum of all ele to high
           lo=min(lo,arr[i]);       // or just perform this loop instead of sorting the array (both methods are same)
        }
        while(lo<=hi)
        {                  //APPLY BINARY SEARCH
            int mid=(lo+hi)/2;         //CALCULATE THE MIDDLE VALUE
            
            if(allocationPossible(arr,mid,k,n))
            {        //CHECK WHETHER ALLOCATION OF BOOK IS POSSIBLE OR NOT
                res=mid;
                hi=mid-1;               //IF YES THEN REDUCE THE BOUNDARY BY NEGATING HIGH
            }
            else
            lo=mid+1;               //IF NO THEN INCREASE LOW
        }
        return lo;                  //RETURN FINAL ANS AS LO OR AS RES
    }
};