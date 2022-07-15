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
    
    key[0]=0;
    
    for(int count=0 ; count<n-1 ;count++) // since spanning tree has n-1 edges so iterate upto n-1
    {
        int mini=INT_MAX , par;
        
        for(int j=0 ;j<n ;j++) // finds min val
        {
            if(mst[j]==false && key[j]<mini)
            {
                mini=key[j]; 
                par=j;
            }
            
        }
        
        mst[par]=true;
        
        for(auto it:adj[par])
        {
            if(mst[it.first]==false && it.second<key[it.first])
            {
                key[it.first]=it.second;
                parent[it.first]=par;
            }
        }
    }
    
    for(int i=1 ; i<n ;i++)
    {
        cout<<parent[i]<<" ";
    }

    return 0;
}
