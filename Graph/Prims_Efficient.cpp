#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,e;
    cin>>n>>e;
    vector<pair<int,int>>adj[n+1];
    
    for(int i=0 ;i<e ;i++)
    {
        int u ,v,w;
        cin>>u>>v>>w;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    int parent[n] , key[n] ;
    bool mst[n];
    
     
    
    for(int i=0 ;i<n ;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    
    priority_queue<pair<int,int> , vector<pair<int,int>>  ,greater<pair<int,int>>>pq;
    
    key[0]=0;
    parent[0]= -1;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        int par = pq.top().second;
        pq.pop();
    
        mst[par]=true;
        
        for(auto it:adj[par])
        {
            if(mst[it.first]==false && it.second<key[it.first])
            {
                key[it.first]=it.second;
                parent[it.first]=par;
                pq.push({key[it.first],it.first});
            }
        }
    }
    
    for(int i=1 ; i<n ;i++)
    {
        cout<<parent[i]<<" ";
    }

    return 0;
}
