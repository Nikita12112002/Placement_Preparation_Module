// Three steps->
// toposort
// transposethe graph
// dfs according to finishing time. 

//Tarjan’s Algorithm: The Tarjan’s Algorithm is an efficient graph algorithm that is used to find the Strongly Connected Component(SCC) in a directed graph by using only one DFS traversal in linear time complexity.
//Kosaraju’s Algorithm: The Kosaraju’s Algorithm is also a Depth First Search based algorithm which is used to find the SCC in a directed graph in linear time complexity.

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int>adj[], vector<int>&vis , int node , int n , stack<int>&st)
{
    vis[node]=1;
    for(auto it : adj[node])
    {
        if(vis[it]==0)
        dfs(adj,vis,it,n,st);
    }
    st.push(node);
}

void topoSort(vector<int>adj[] , int n,stack<int>&st)
{
    vector<int>vis(n,0);
    
    
    for(int i=0 ;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(adj,vis,i,n,st);
        }
    }
}

void rev_dfs( int node, vector<int>&vis,vector<int>transpose[])
{
    cout<<node<<" ";
    
    vis[node]=1;
    for(auto it : transpose[node])
    {
        if(vis[it]==0)
        rev_dfs(it,vis,transpose);
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    vector<int>adj[n];
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0 ;i<e ;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    topoSort(adj,n,st);
    
    vector<int>transpose[n];
    for(int i=0 ;i<n;i++)
    {
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
            
        }
    }
    
   while(!st.empty())
   {
       int node = st.top();
       st.pop();
       
       if(vis[node]==0)
       {
           cout<<"SCC:";
           rev_dfs(node,vis,transpose);
           cout<<endl;
       }
   }
    return 0;
}
