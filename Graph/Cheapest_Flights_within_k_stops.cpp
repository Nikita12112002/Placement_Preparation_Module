// approach -1 --> a liitle variation of dijkstra 
// using priority queue
// gives tle on leetcode
// TC: O(n+e)logn

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];
        
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       
        
      
        pq.push(make_tuple(0,src,0));
        while(!pq.empty())
        {
            auto [cost,node,stop] = pq.top();
            pq.pop();
            
            if(node==dst)
                return cost;
            
            if(stop>k)
                continue;
            
            for(auto it : adj[node])
            {
                pq.push(make_tuple(cost+it.second ,it.first,stop+1));
                
            }
            
        }
        
        return -1;
    }
};

//approach-2 
//