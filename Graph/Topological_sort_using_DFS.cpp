#include <bits/stdc++.h>

using namespace std;

void topoSort(vector<int>adj[] , int visited[] , stack<int>&st , int node)
{
    visited[node]=1;
    
    for(auto it : adj[node])
    {
        if(visited[it]==0)
        {
            topoSort(adj,visited,st,it);
        }
    }
    
    st.push(node);
}

vector<int> dfs(vector<int>adj[] , int n)
{
    stack<int>st;
   int visited[n];
    
    for(int i=0 ;i<n ;i++)
    {
        visited[i]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            topoSort(adj,visited,st,i);
        }
    }
    
    vector<int>ans;
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main()
{
   int n,e ;
   cin>>n>>e;
   
   vector<int>adj[n+1];
   
   for(int i=0 ;i<e ;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);  // for directed graph.
   }
   
  
   for(auto it : dfs(adj,n))
   {
       cout<<it<<" ";
   }
    return 0;
}
