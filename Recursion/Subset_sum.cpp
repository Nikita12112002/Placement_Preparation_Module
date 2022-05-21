//Brute force solution- power set method 
//TC: O(n*2^n)

// optimal sol - recursion TC:O(2^n) sc:(2^n)

// Note- in subset questions always think of pick and non-pick approach.

class Solution
{
public:

void solve(vector<int>&a , int n , int i , int sum ,vector<int>&ans)
{
    if(i==n)
    {
        ans.push_back(sum);
        return;
    }
    else
    {
        solve(a,n,i+1,sum+a[i],ans);
        solve(a,n,i+1,sum,ans);
    }
}

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int>ans;
        solve(arr,n,0,0,ans);
        return ans;
    }
};