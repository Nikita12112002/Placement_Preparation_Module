// also known by the name chess tournament
//optimal approach --using binary search --TC:O(nlogn)

bool blackbox(int mid , vector<int>&positions , int n , int c )
{
    int cordinate=positions[0],count=1;
    for(int i=1 ; i<n ;i++)
    {
        if(positions[i]-cordinate>=mid) 
        {   
            count++;
            cordinate=positions[i];
        }
        
     }
    
  // it means all the cows are placed if count is equal to c 
        // and if count is greater than c then it means that all the cows are already placed
        // and there can be more such cows which can be placed.
    if(count>=c) 
    return true;
     return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(),positions.end()); 
    int low=1,high=positions[n-1]-positions[0]; // min distance between the cows can be 1 
    //and max dist can be the diff between the last value and first value.
    
    int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(blackbox(mid,positions,n,c)==true)// check if all the cows can be placed or not
        {   
            res=mid; // if can be placed then store that result and look for higher value ,thats why we have shifted low=mid+1
            low=mid+1;
        }
        else
            high=mid-1; // if cannot be placed then shift high bcoz the given distance is not suitable
  // to place all the cows       
    }
    return res;
}