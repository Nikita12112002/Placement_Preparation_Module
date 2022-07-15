#include <bits/stdc++.h>
using namespace std;

void Dijkstra(vector<pair<int,int>>adj[],int n , int src)
{
    int dis[n+1];
    for(int i=0 ;i<=n;i++)
    {
        dis[i]=INT_MAX;
    }
    
     dis[src]=0;
    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    pq.push({0,src}); // distance of first node from itself is 0 
    
    while(!pq.empty())
    {
        auto node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node])
        {
            if(dis[node]+ it.second<dis[it.first])
            {
                dis[it.first]= dis[node] + it.second;
                
                pq.push({dis[it.first] , it.first});
            }
        }
    }
    
    
    for(int i=1 ;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
}

int main()
{
    int n ,e;
    cin>>n>>e;
    
    vector<pair<int,int>>adj[n+1];
    
    for(int i=0 ;i<e ;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});  // undirected graph
        
    }
    
    int src;
    cin>>src;
    
    Dijkstra(adj,n,src);

    return 0;
}
