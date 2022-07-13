#include <bits/stdc++.h>
using namespace std;

bool bfsCycleCheck(vector<int>adj[] , bool visited[] , int s)
{
    visited[s]=true;
    queue<pair<int,int>>q;
    q.push({s,-1});
    
    while(!q.empty())
    {
        auto node = q.front().first;
        auto par = q.front().second;
        
        q.pop();
        
        for(auto it: adj[node])
        {
            if(visited[it]==false)
            {
                visited[it]=true;
                q.push({it,node});
            }
            
            else if(it!=par)
            {
                return true;
            }
            
        }
        
    }
    return false;
}
bool bfs(vector<int>adj[] ,int n)
{
    bool visited[n];
    
    for(int i=0 ;i<n ;i++)
    {
        visited[i]=false;
    }
    
    for(int i=0 ;i<n ;i++)
    {
        if(visited[i]==false)
        {
            if((bfsCycleCheck(adj,visited,i))==true)
            {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    
    vector<int>adj[n+1];
    
    for(int i=0 ;i<e ;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
        if(bfs(adj,n)==true)
        {
           cout<<"Cycle found";
        }
        
        else
          cout<<"Cycle Not present";
    
    return 0;
}