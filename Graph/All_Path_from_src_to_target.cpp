class Solution {
public:
    
    void dfs(vector<vector<int>>graph , vector<vector<int>>&res , vector<int>&ans , int node , vector<int>&vis , int n)
    {
        ans.push_back(node);
        if(node==n-1)
        {
         
        res.push_back(ans);
        }
          
        vis[node]=1;
        
        for(auto it:graph[node])
        {
            if(!vis[it])
                dfs(graph,res,ans,it,vis,n);
        }
       
        ans.pop_back();
        vis[node]=0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>>res;
        vector<int>ans;
        vector<int>vis(n,0);
        dfs(graph,res,ans,0,vis,n);
        return res;
    }
};