class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
     priority_queue<pair<int,int>>q;
        unordered_map<int,int>m;
       vector<int>ans; 
        for(auto it:nums)
        {
            m[it]++;
            
        }
        
        for(auto it:m)
        {
            q.push({it.second,it.first});
        }
        int i=1;
        while(!q.empty())
        {
            if(i>k)
                break;
             ans.push_back(q.top().second);
            q.pop();
            i++;
        }
        return ans;
    }
};