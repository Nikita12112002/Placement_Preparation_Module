class Solution {
public:
    
    int dfs(int src , vector<int>adj[] , vector<int>&subtree ) // this dfs will store the size of each node which is equal to no of nodes in its subtree including that node also
    {
       int ans=1;
        for(auto it:adj[src])
        {
            ans=ans+dfs(it,adj,subtree);
        }
        
        return subtree[src]=ans;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
      int n=parents.size();
      vector<int>subtree(n,0);
      vector<int>adj[n];
      
        for(int i=1 ;i<n ;i++)
        {
            adj[parents[i]].push_back(i); // store the adj but only in one direction that is only the adjacent which is in the downword direction
        }
        
        dfs(0,adj,subtree);
        long long count=0;
        long long maxi=0;
        long long prod;
        for(int i=0 ;i<n ;i++)
        {
            prod=1;
            long long rem_nodes = n-subtree[i]; // tells us that no of nodes excluding that node and its subtree
            prod=max(prod,rem_nodes);  
        
        
        for(auto it:adj[i])
        {
            prod = prod*subtree[it]; // for calculating prod of nodes below i;
        }
         
        if(prod>maxi)  // it means we have found the largest value that we haven't found yet.
        {
            maxi=prod;
            count=1;
        }
        else if(prod==maxi)  // if prod is equal to max then increment the count as we have to return the no of nodes having maximum prod;
            count++;
        }  
        return count;
    }
};