#include <bits/stdc++.h>

using namespace std;

void topoSort(vector<pair<int,int>>adj[] , int vis[] , int node , int n , stack<int>&st)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(vis[it.first]==0)
        {
         topoSort(adj,vis,it.first,n,st);
        }
    }
    
    st.push(node);

}

void shortestPath(vector<pair<int,int>>adj[],int n)
{
    // logic of topoSort
    int vis[n+1];
    stack<int>st;
    
    for(int i=0 ;i<n ;i++)
    {
        vis[i]=0;
    }
    
    for(int i=0 ; i<n;i++)
    {
        if(vis[i]==0)
        {
            topoSort(adj,vis,i,n,st);
        }
    }
    
    // logic of shortest path
    
    int dis[n];
    for(int i=0 ;i<n ;i++)
    {
        dis[i]=INT_MAX;
    }
    
    dis[0]=0; // source node is 0->given
    
    while(!st.empty())
    {
        auto node = st.top();
        st.pop();
        
        if(dis[node]!=INT_MAX)
        {
            for(auto it : adj[node])
            {
                if(dis[node]+it.second< dis[it.first])
                {
                    dis[it.first] = dis[node]+it.second;
                }
            }
        }
    }
    
    for(int i=0 ;i<n ;i++)
    {
        if(dis[i]==INT_MAX)
        cout<<"INF"<<" ";
        
        else
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
        
    }
    
    shortestPath(adj,n);

    return 0;
}
