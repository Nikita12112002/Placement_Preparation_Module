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
