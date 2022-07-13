class Solution {
public:
    
    bool checkBipartite(vector<vector<int>>graph, int color[],int s)
    {
        queue<int>q;
        color[s]=1;
        q.push(s);
      
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
         for(auto it : graph[node])
         { 
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            
            else if(color[it]==color[node])
                return false;
        }
        }  
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int color[n];
        
        for(int i=0 ;i<n ;i++)
        {
            color[i]=-1;
        }
        
        for(int i=0 ;i<n;i++)
        {
            if(color[i]==-1)
            {
               
                
                if(checkBipartite(graph,color,i)==false)
                    return false;
            }
        }
        return true;
    }
};