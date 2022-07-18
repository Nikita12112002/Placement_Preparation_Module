// concept->find no of disconnceted components

class Solution {
public:
    int count=0;
    
    void dfs(vector<int>adj[] , vector<int>&vis , int node , int n)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
                dfs(adj,vis,it,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>adj[n+1];
        
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
        }
        
        vector<int>vis(n+1,0);
        
        for(int i=0 ;i<n ;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(adj,vis,i,n);
            }
        }
        return count;
    }
};