class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        int n = numCourses;
        vector<int>ans;
        vector<int>res;
        vector<int>ind(n);
        vector<int>adj[n];
        
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0 ;i<n ;i++)
        {
            for(auto it:adj[i])
            {
                ind[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0 ;i<n ;i++)
        {
            if(ind[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node])
            {
                ind[it]--;
                if(ind[it]==0)
                    q.push(it);
            }
        }
        
        if(ans.size()!=n)
            return res;
        
        return ans;
    }
};