#include <bits/stdc++.h>

using namespace std;

bool checkCycle(vector<int>adj[] , int vis[] , int dfsvis[] , int node)
{
    vis[node]=1;
    dfsvis[node]=1;
    
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            if(checkCycle(adj,vis,dfsvis,it)==true)
              return true;
        }
        
        else if(dfsvis[it]==1)
         return true;
    }
    
    dfsvis[node]=0;
    return false;
}

bool checkdfs(vector<int>adj[] , int n)
{
    int vis[n] , dfsvis[n];
    
    for(int i=0 ;i<n;i++)
    {
        vis[i]=0;
        dfsvis[i]=0;
    }
    
    for(int i=0 ;i<n ;i++)
    {
        if(vis[i]==0)
        {
            if(checkCycle(adj,vis,dfsvis ,i)==true)
              return true;
        }
        
    }
    
    return false;
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
   
   if(checkdfs(adj,n)==true)
     cout<<"cycle found in directed graph";
     
    else
    cout<<"cycle not found";
    return 0;
}
