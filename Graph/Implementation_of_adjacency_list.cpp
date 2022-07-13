#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,m;
    cin>>n>>m;
    
    vector<int>adj[n+1];
    
    for(int i=0 ;i<m ;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for directed graph omit this line
    }
    
    for(int i=0 ;i<=n;i++)
    {
        cout<<"adjacent of"<<i<<"->";
        for(auto it : adj[i])
         cout<<it<<",";
         
         cout<<endl;
    }
    

    return 0;
}
