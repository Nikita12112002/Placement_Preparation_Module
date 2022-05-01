//Brute force

int longestConsecutive(vector<int>& nums) 
{
	if(!size(nums))
     return 0;
	sort(begin(nums), end(nums));

	int longest = 0, cur_longest = 1;

	for(int i = 1; i < size(nums); i++) 
		if(nums[i] == nums[i - 1]) 
        continue;
		else if(nums[i] == nums[i - 1] + 1) 
        cur_longest++; // consecutive element - update current streak length
		else 
        {
            longest = max(longest, cur_longest);
           cur_longest = 1;  // reset current streak length
        }
	return max(longest, cur_longest);
}


//optimal

int longestConsecutive(vector<int>& nums) {
        
        //TC:O(n)+O(n)+O(n)=O(3n)
        //sc:O(n)
        
        unordered_set<int>s;
        int n=nums.size();
        
        for(int i=0 ;i<n;i++)
        {
           s.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0 ;i<n;i++)
        {
            int count=1;
            //checking for one less value in set
            if(s.find(nums[i]-1)==s.end()) 
            {
                int c=nums[i];
                //iterating from one greater value
                while(s.find(c+1)!=s.end())
                {
                    c=c+1;
                    count++;
                }
                
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
