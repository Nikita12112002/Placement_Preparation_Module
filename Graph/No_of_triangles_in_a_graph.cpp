int triangleInGraph(vector<vector<int>> &graph, int v) {
    // Write your code here
    bool isDirected=false;
    int count=0;
    
    for(int i=0 ;i<v ;i++)
    {
        for(int j=0 ;j<v ;j++)
        {
            for(int k=0 ; k<v ;k++)
            {
               if(graph[i][j]==1 && graph[j][k]==1 && graph[k][i])
               {
                   count++;
                   
               }
            }
        }
    }
    
    if(isDirected)
        count=count/3;
    
    else
        count=count/6;
    return count;
}