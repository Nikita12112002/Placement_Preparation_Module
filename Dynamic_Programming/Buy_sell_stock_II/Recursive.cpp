class Solution {
public:

    int dfs(vector<int>&prices , int i , int buy ,int n)
    {
        if(i==n)
            return 0;
        
        if(buy==1)
        {
            return max(-prices[i]+dfs(prices,i+1,0,n) , 0+dfs(prices,i+1,1,n));
        }
          return max(prices[i]+dfs(prices,i+1,1,n) , 0+dfs(prices,i+1,0,n));
        
            
    }
    int maxProfit(vector<int>& prices) {
        
       int n = prices.size();
        return dfs(prices,0,1,n);
    }
};