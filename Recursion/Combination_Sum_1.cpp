// always apply pick and non pick approach when we have to 
//find combination in an array.
// TC:O(2^target * k)

class Solution {
public:
    
    void solve(int index , vector<int> candidates , int target , vector<int>& ds , vector<vector<int>>& ans)
    {
        //ex-2,3,6,7
        if(index==candidates.size())
        {
            if(target==0)
             ans.push_back(ds);
            return;
        }
        
        // 2<=7 --->true
        if(candidates[index]<=target)
        {
            // put 2 in ds
            ds.push_back(candidates[index]);
            // left recur call recursively with reduced target , and same index
            // index will remain same because we can take a value multiple times
            solve(index,candidates,target-candidates[index],ds,ans);
            // delete the element whose left call has been called
            ds.pop_back();
        }
        
        // right recursion
        solve(index+1,candidates,target,ds,ans);
        
        // note- pop statement will only work for the calls whose left calls has been executed .for those whose left call wasn't executed it means the caller doesnot goes in if condition and execute 27 line no that is right call so there is no pop statement in right call .after recusrion is complete for the right call the caller will simply return without poppping anything from the ds.
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,candidates,target,ds,ans);
        return ans;
    }
};