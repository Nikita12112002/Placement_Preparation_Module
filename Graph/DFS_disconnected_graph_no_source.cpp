#include <bits/stdc++.h>

using namespace std;
void dfs(int node,bool visited[] ,vector<int>adj[])
{
    visited[node]=1;
    
    cout<<node<<" ";
    
    for(auto it:adj[node]){
        if(!visited[it])
        dfs(it,visited,adj);
    }
}
void CheckDfs(int n,vector<int>adj[] ,int s)
{
   bool visited[n];
   
   for(int i=0 ;i<n;i++)
   {
       visited[i]=false;
   }
   for(int i=0 ;i<n ;i++)
   {
       if(visited[i]==false)
       {
         dfs(i,visited,adj);
       }
   }
}

int main()
{
   int n;
   cin>>n;
   int e;
   cin>>e;
   vector<int>arr[n+1];
   for(int i=0;i<e;i++){
       int u,v;
       cin>>u>>v;
       arr[u].push_back(v);
       arr[v].push_back(u);
   }
  CheckDfs(n,arr,0);
   
    return 0;
}