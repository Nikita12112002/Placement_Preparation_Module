// concept --> cycle detection in an directed graph

class Solution {
public:
    bool dfs(vector<int>adj[] , vector<int>&vis , int node , int n , vector<int>&dfsvis)
  {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(adj,vis,it,n ,dfsvis))
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
                
        }
        dfsvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
       int n = numCourses; 
       vector<int>adj[n];
       vector<int>vis(n,0);
       vector<int>dfsvis(n,0);
       for(auto it:pre)
       {
           adj[it[1]].push_back(it[0]);
       }
    
        for(int i=0 ;i<n ;i++)
        {
            if(!vis[i])
            {
              if(dfs(adj,vis,i,n,dfsvis))
                  return false;
            }
        }
        return true;
    }
};