// NOTE--> return all possible ways.
// also return the combinations in lexographical order

class Solution{
    public:
    
    void solve(int i , int j , vector<string>& ans , vector<vector<int>>& vis ,vector<vector<int>>& m , int n , int di[], int dj[],string s)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return ;
        }
        
        string str="DLRU";
        
        for(int ind=0 ;ind<4 ;ind++) // checking all the directions one by one in order DLRU
        {
            int x=i+di[ind];         // determing x and y coordinates of index at which we want to move
            int y=j+dj[ind];
            
            if(x>=0 && y>=0 && x<n && y<n && vis[x][y]!=1 && m[x][y]!=0) // checking wheather the index at which we want to move
                                                                         // is a valid index
            {
                vis[i][j]=1;                        // marked that position true bcoz we cannot visit same index more than once
                solve(x,y,ans,vis,m,n,di,dj,s+str[ind]); 
                vis[i][j]=0;                       // backtracking step
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        string s="";
        int di[4]={1,0,0,-1};
        int dj[4]={0,-1,1,0};
        
        if(m[0][0]==1)
        {
         solve(0,0,ans,vis,m,n,di,dj,s);
        }
        return ans;
    }
};