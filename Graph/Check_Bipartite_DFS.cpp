class Solution {
public:
    
    bool checkBipartite(vector<vector<int>>graph , int color[] , int s)
    {
        for(auto it:graph[s])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[s];
                if(checkBipartite(graph,color,it)==false)
                {
                    return false;
                }
            }
            
            else if(color[it]==color[s])
                return false;
                
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
        
        for(int i=0 ;i<n ;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                
                if(checkBipartite(graph,color,i)==false)
                    return false;
            }
        }
        
        return true;
    }
};