class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>q;
        
        for(auto it:nums)
        {
            q.push(it);
        }
        int i=1;
        while(!q.empty())
        {
            if(i==k)
                break;
            q.pop();
            i++;
        }
        return q.top();
    }
};