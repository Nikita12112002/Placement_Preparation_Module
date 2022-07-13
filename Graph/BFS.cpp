#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[] , int n , int s)
{
    queue<int>q;
    
    bool visited[n];
    
    for(int i=0 ; i<n ;i++)
    {
        visited[i]=false;
    }
    
    visited[s]=true;
    q.push(s);
    
    while(q.empty()==false)
    {
       int u=q.front();
        cout<<u<<" ";   // print the bfs traversal
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

int main()
{
    
    int n , e;
    cin>>n>>e;
    
    vector<int> adj[n+1];
    
    for(int i=0 ; i<e ;i++)
    {
        int u,v;      // nodes starts from 0 , so enter edges accordingly
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        
        
        cout<<"BFS TRAVERSAL IS :"<<endl;
        bfs(adj,n,0); // source is given
        
    

    return 0;
}
