bool isSafe(int node ,int color[],bool graph[101][101] ,int col,int n )
{
    //k!=node--> optional statement 
    // graph[k][node]==1 --> if there is an edge(adjacent) between k and node
    // color[k]==col --> if edge is present then check wheather it is colored with the same color which u want
    // if yes then return false showing that the given node cannot be colored with this particular chosen color
    //otherwise return false
    
    for(int k=0 ;k<n ;k++)
    {
      if(k!=node && graph[k][node]==1 && color[k]==col)
      return false;
      
    }
    
    return true;
}

bool solve(int node ,bool graph[101][101] , int color[] ,int m ,int n)
{
    if(node==n)
     return true; // this statement will never get executed 
     //if given colors are not sufficient to color all the node
    
    for(int i=1 ; i<=m ; i++) // try all the color 
    {
        if(isSafe(node,color,graph,i,n))
          {
              color[node]=i;
              
              if(solve(node+1,graph,color,m,n))
                return true;
              else   
              color[node]=0;   // this statement will execute when below return false will execute
          }
          
          
    }
    return false; // if all the node are not able to color with given no of colors
    
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    int color[n]={0};
    
    if(solve(0,graph,color,m,n)==true)
     return true;
    
    return false;
}
