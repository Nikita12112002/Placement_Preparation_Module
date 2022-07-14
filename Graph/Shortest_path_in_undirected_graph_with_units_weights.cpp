#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,e ;
   cin>>n>>e;
   
   vector<int>adj[n+1];
   
   for(int i=0 ;i<e ;i++)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);  
       adj[v].push_back(u);
   }
   
  int dist[n];
  for(int i=0 ;i<n ;i++)
  {
      dist[i]=INT_MAX;
  }
  
  queue<int>q;
  q.push(0);   // source is given as 0;
  dist[0]=0;
  
  while(!q.empty())
  {
      auto node = q.front();
      q.pop();
      
      for(auto it:adj[node])
      {
          if(dist[node]+1<dist[it])
          {
              dist[it]=dist[node]+1;
              q.push(it);
          }
      }
  }
  
  for(int i=0 ;i<n ;i++)
  {
      cout<<dist[i]<<" ";
  }
     
    return 0;
}
