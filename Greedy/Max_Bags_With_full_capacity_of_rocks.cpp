class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        vector<int>cap;
        
        for(int i=0 ;i<capacity.size() ;i++)
        {
            cap.push_back(capacity[i]-rocks[i]);
        }
        
        sort(cap.begin(),cap.end());
        int count=0 ,i=0;
        
        while(i<cap.size() && additionalRocks!=0)
        {
            if(cap[i]==0)
                count++;
            
            else
            {
                if(cap[i]<=additionalRocks)
                {
                    additionalRocks=additionalRocks-cap[i];
                    count++;
                }
            }
            i++;
        }
       return count; 
    }
};