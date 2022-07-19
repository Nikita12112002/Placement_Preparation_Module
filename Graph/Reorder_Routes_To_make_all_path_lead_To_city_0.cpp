class Solution {
public:
    int count=0;
    
    void dfs(vector<int>adj[] , vector<int>&vis , int& count , int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[abs(it)])
            {
                if(it>0) // there is an outward edge so we have to reverse the dir hence inc count;
                    count++;
                dfs(adj,vis,count,abs(it)); 
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
  
        vector<int>adj[n];
        
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);  // storing the negative adjacent for reverse connection
            
        }
        vector<int>vis(n,0);
        dfs(adj,vis,count,0); // 0 is given because we have to start dfs from 0
        return count;
    }
};