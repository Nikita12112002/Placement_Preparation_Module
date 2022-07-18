//concept--> simple dfs of disconnected components.
// just count nodes in every disconnected components

class Solution {
public:
    
    void dfs(vector<int>adj[],vector<int>&vis , int node , int n , int& count)
    {
        vis[node]=1;
        count++;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(adj,vis,it,n,count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        vector<int>ans;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i=0 ;i<n ;i++)
        {
            int count=0;
            if(!vis[i])
                dfs(adj,vis,i,n,count);
            ans.push_back(count);
        }
        long long sum=0;
        for(auto it:ans)
        {
            long long rem = n-it;
            sum = sum+(long long)(it)*(long long)(rem);

        }
        
        return sum/2;  // becaus every pair is counted twice
    }
};