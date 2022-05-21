  class Solution
{
    public:
    
      bool static comp(Item ele1, Item ele2) {
         double s1 = (double) ele1.value / (double) ele1.weight;
         double s2 = (double) ele2.value / (double) ele2.weight;
         return s1 > s2;
      }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        // example- sample test case1.
       
        sort(arr,arr+n,comp);
        
        int weight=0 ;
        double profit=0.0;
        
        for(int i=0 ; i<n ;i++)
        {
            if(weight+arr[i].weight <=W)
            {
                weight = weight+arr[i].weight;
                profit= profit+arr[i].value;
            }
           
           // when i=2
           // 30kg---->120 profit
           //1kg------>120/30 profit
           // rem 20 kg ----->(120/30)*20
            else
            {
                int rem = W-weight;
                profit=profit+(arr[i].value/(double)arr[i].weight)*(double)rem;
                break;
            }
        }
        
        return profit;
    }
    
    
        
};