#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node , bool visited[] ,vector<int>adj[] , int par)
{
    visited[node]=true;
    
    for(auto it:adj[node])
    {
        if(visited[it]==false)
        {
          if(checkCycle(it,visited,adj,node)==true)
            {
                return true;
            }
        }
        
        else if(it!=par)
         return true;
    }
    
    return false;
}
bool CheckDfs(int n,vector<int>adj[])
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
         if(checkCycle(i,visited,adj,-1)==true)
         {
             return true;
         }
       }
   }
   
   return false;
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
   if(CheckDfs(n,arr)==true)
   {
       cout<<"cycle found";
   }
   
   else
   cout<<"Cycle not present";
   
    return 0;
}