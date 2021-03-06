#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[] , int s , bool visited[])
{
    queue<int>q;
    
    
    visited[s]=true;
    q.push(s);
    
    while(q.empty()==false)
    {
       int u=q.front();
        cout<<u<<" ";
        q.pop();
        
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
    
}

void bfs_dis(vector<int>adj[] , int n)
{
    bool visited[n];
    
    for(int i=0 ; i<n ;i++)
    {
        visited[i]=false;
    }
    
    for(int i=0 ; i<n ;i++)
    {
        if(visited[i]==false)
        {
           
            bfs(adj , i ,visited);
        }
    }
    
}

int main()
{
    
    int n , e;
    cin>>n>>e;
    
    vector<int> adj[n+1];
    
    for(int i=0 ; i<e ;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        
        
        cout<<"BFS TRAVERSAL IS :"<<endl;
        bfs_dis(adj,n); // source is given
        
    

    return 0;
}
