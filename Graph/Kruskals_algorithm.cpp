#include <bits/stdc++.h>

using namespace std;

int findPar(int node , vector<int>&par)
{
    if(par[node]==node)
      return node;
      
      par[node]=findPar(par[node],par);
      return par[node];
}

void union_find(int a , int b , vector<int>&rank , vector<int>&par)
{
    a=findPar(a,par);
    b=findPar(b,par);
    
    if(rank[a]<rank[b])
      par[a]=b;
      
    else if(rank[a]>rank[b])
      par[b]=a;
      
    else
    {
        par[a]=b;
        rank[b]++;
    }
}

int main()
{
   int n ,e;
   cin>>n>>e;
   
   vector<pair<int ,pair<int,int>>>a(n+1);
   
   for(int i=0 ;i<e ;i++)
   {
       int w,u,v;
       cin>>w>>u>>v;
       
       a.push_back({w,{u,v}});  // directed edge.
   }
   
   sort(a.begin(),a.end());
   vector<int>rank(n+1,0);
   vector<int>par(n+1);
   vector<pair<int,int>>mst;
   
   for(int i=0 ;i<=n ;i++)
   {
       par[i]=i;
   }
   
   int cost=0;
   for(auto it:a)
   {
       if(findPar(it.second.first,par)!=findPar(it.second.second,par))
       {
           cost = cost + it.first;
           mst.push_back({it.second.first,it.second.second});
           union_find(it.second.first , it.second.second , rank ,par);
       }
   }
   
   cout<<"Minimum cost of spanning tree is"<<cost<<endl;
   
   cout<<"Mininum spanning tree"<<endl;
   
   for(auto it:mst)
     cout<<it.first<<" "<<it.second<<endl;

    return 0;
}
