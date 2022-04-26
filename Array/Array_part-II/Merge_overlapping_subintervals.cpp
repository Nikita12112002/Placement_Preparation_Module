// First question =>  wheather the input is in the sorted order or not 
// bcoz here in this questions input must be in the sorted order

//Approach-1: TC:O(NlogN) SC:O(n2)
//Approach-2: TC:O(NlogN) for sorting +O(N) for lineraly traversing the array, 
//SC:O(N) in worst-case

// See explanation with example in Merge_Interval.jpg file

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
	 vector<vector<int>>ans;
        
        if(intervals.size()==0)
            return ans;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int>temp=intervals[0];
        
        for(auto it : intervals)
        {
            if(it[0]<=temp[1])
                temp[1]=max(it[1],temp[1]);
            
            else
            {
                ans.push_back(temp);
                temp=it;
            }
        }
      ans.push_back(temp);
      return ans;
    
}

