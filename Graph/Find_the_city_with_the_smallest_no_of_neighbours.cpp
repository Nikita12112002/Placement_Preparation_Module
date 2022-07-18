class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd-warshell algorithm -->all pair shortest path algorithm
        
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX)); //2d-distance vector storing all pair shortest path
        
        for(int i=0 ; i<n ;i++)
            dis[i][i]=0;
    
        
        for(auto it:edges)
        {
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
            
        }
        
        //floyd-warshell logic to update distance to get shortest path
        

        for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
	                if(dis[i][k]==INT_MAX or dis[k][j]==INT_MAX)
	                continue;
	                
	                if(dis[i][j]==INT_MAX)
	                dis[i][j] = dis[i][k] + dis[k][j];
	                
	                else 
	                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	            }
	        }
	    }
        //count the cities which has less dis than the threshold distance
        
        int count=0,ans,maxi=n;
        
        for(int i=0 ;i<n ;i++)
        {
            count=0;
            for(int j=0 ;j<n ;j++)
            {
                if(i!=j)
                {
                    if(dis[i][j]<=distanceThreshold)
                        count++; // like through city 0 we can move to 2 cities which are less than or equal to threshold so count=2;
                    
                }
            }
            
        // each time we finishes with one city we will check does this count is smaller than count of previous cities
            
            if(count<=maxi)
            {
                maxi=count; // update the count so that may be in future we get lesser count than this
                ans=i;     // if yes stores the city no.
            }
            
                
        }
        
        return ans;
    }
};