//Brute force -> recursion--> TC:O(n*n!) 
// n! for generating all the permutaion
// n for putting all the permutations into your data structure
//then n! time for sorting n! list of permutations..
//so recursion approach will take alot of time

//optimal solution-->iterative method

class Solution {
public:
    string getPermutation(int n, int k) {
    // ex- 1,2,3,4
        int fact=1;
        vector<int>ans;
        
        //just to store 1 to n values in the array 
        for(int i=1 ;i<n ;i++)
        {
            // counting no of ways .
           // 1_ _ _ =6ways
           // 2_ _ _ =6ways
           // 3_ _ _ =6ways
            fact=fact*i; 
            ans.push_back(i);
        }
       
        ans.push_back(n); // push the last ele in vector
        string s="";
        k=k-1;  // k is decremented by one bcoz we are taking 0 based indexing
        while(true)
        {
            //ex- 1,2,3,4(only first iteration is shown in ex below)
            // k=16/6=2
            // value at index 2 is 3 so first value of resultant                 // string will be 3.
            s=s+to_string(ans[k/fact]); 
            
         //now erase 3 from array as it becomes a part of res string
            ans.erase(ans.begin()+k/fact);
            
            if(ans.size()==0)
                break;
            
          // k=16%6=4 (updated value of k)
            
            k=k%fact;
            
          // fact=>6/3=2  
            fact=fact/ans.size();
        }
        
        return s;
    }
};
