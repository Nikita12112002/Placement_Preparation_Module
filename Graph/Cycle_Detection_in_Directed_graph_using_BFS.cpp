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
       adj[u].push_back(v);  // for directed graph.
   }
   
   vector<int>indegree(n+1);
   
   for(int i=0 ;i<n;i++)
   {
       for(auto it:adj[i])
       {
           indegree[it]++;
       }
   }
   
   queue<int>q;
   
   for(int i=0 ;i<n;i++)
   {
       if(indegree[i]==0)
        q.push(i);
   }
   
   vector<int>ans;
   
   while(!q.empty())
   {
       auto node = q.front();
       q.pop();
       
       ans.push_back(node);
       
       for(auto it :adj[node])
       {
           indegree[it]--;
           if(indegree[it]==0)
            q.push(it);
       }
   }
   
   if(ans.size()!=n)
     cout<<"Graph is cyclic";
   
   else
     cout<<"Acyclic";
     
    return 0;
}
