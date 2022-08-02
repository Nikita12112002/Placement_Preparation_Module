int dfs(vector<int>weight , vector<int>value , int i , int w)
{
    if(i==0)
    {
        if(weight[i]<=w)
            return value[i];
        return 0;
    }
    int notpick = dfs(weight,value,i-1,w);
    int pick =0;
    if(weight[i]<=w)
        pick = value[i]+dfs(weight ,value , i-1 , w-weight[i]);
    return max(notpick , pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
   return dfs(weight , value , n-1 , maxWeight);
}