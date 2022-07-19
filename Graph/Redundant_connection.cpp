class Solution {
public:
    
    int findPar(int node , vector<int>&par)
    {
        if(par[node]==node)
            return node;
        
        par[node]=findPar(par[node],par);
        return par[node];
    }
    
    void union_find(int a , int b , vector<int>&rank , vector<int>&par)
    {
        a=findPar(a,par);
        b=findPar(b,par);
        
        if(rank[a]<rank[b])
            par[a]=b;
        if(rank[a]>rank[b])
            par[b]=a;
        else
        {
            par[a]=b;
            rank[b]++;
        }
    }
   vector<int>findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int>ans;
         vector<int>par(n+1);
         vector<int>rank(n+1,0);
        
        for(int i=0 ;i<=n ;i++)
        {
            par[i]=i;
        }
        for(auto it:edges)
        {
            if(findPar(it[0],par)!=findPar(it[1],par))
            {
                union_find(it[0],it[1],rank,par);
            }
            
            else
            {
                ans.push_back(it[0]);
                ans.push_back(it[1]);
                break;
            }
                
        }
        
        return ans;
    }
};