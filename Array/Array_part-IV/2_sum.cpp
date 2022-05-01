// Problem Statement->
// You are given an integer array 'ARR' of size 'N' and an integer 'S'. 
// Your task is to return the list of all pairs of elements such that 
// each sum of elements of each pair equals 'S'

// input->
// 5 0
// 2 -3 3 3 -2

// ouput->
// -3 3
// -3 3
// -2 2

// This is to generate all pairs.

vector<vector<int>> pairSum(vector<int> &arr, int sum)
{
   // Write your code here.
	unordered_map<int, int> m;
   vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
    // Traverse through all elements
    for (int i = 0; i < arr.size(); i++) {
 
        // Search if a pair can be formed with
        // arr[i].
        int rem = sum - arr[i];
        if (m.find(rem) != m.end())
		{
            int count = m[rem];
            for (int j = 0; j < count; j++)
			{
				vector<int>res;
                   res.push_back(rem); 
                   res.push_back(arr[i]);
				ans.push_back(res);
			}
        }
        m[arr[i]]++;
    }
sort(ans.begin(),ans.end());
 return ans;
}