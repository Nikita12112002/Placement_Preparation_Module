#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
   priority_queue<int,vector<int>,greater<int>> q;
    vector<int>ans;
    
    for(int i=0 ;i<k;i++)
    {
        for(int j=0 ;j<kArrays[i].size();j++)
        {
            q.push(kArrays[i][j]);
        }
    }
    
    while(!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}
