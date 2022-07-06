class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {

        int n = nums.size();
        int i, ans = 0, count = 0, prev;
        stack<pair<int, int>> st;

        st.push({nums[n - 1], 0});

        for (int i = n - 2; i >= 0; i--)
        {
            count = 0;
            while (!st.empty() && nums[i] > st.top().first)
            {
                count++;
                count = max(count, st.top().second);

                st.pop();
            }

            ans = max(ans, count);

            st.push({nums[i], count});
        }
        return ans;
    }
};