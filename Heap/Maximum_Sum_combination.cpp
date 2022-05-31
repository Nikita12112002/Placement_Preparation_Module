#include<bits/stdc++.h>
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int C) {

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n=a.size();
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;

    pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
    s.insert({n-1,n-1});
    
    vector<int>ans;
    int k=C;
    while(k--)
    {
       
      auto top = pq.top();
      pq.pop();
      ans.push_back(top.first);

       int l=top.second.first;
       int r=top.second.second;

       if(l>0 && r>0 && s.find({l-1,r})==s.end())
       {
           pq.push(make_pair(a[l-1]+b[r] , make_pair(l-1,r)));
           s.insert({l-1,r});
       }

        if(l>0 && r>0 && s.find({l,r-1})==s.end())
       {
           pq.push(make_pair(a[l]+b[r-1] , make_pair(l,r-1)));
           s.insert({l,r-1});
       }

    }
    return ans;
}