// Roman to integer

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map <char, int> m {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++) 
        {
            if (m[s[i]] < m[s[i+1]])  // MCMXCIV
                ans -= m[s[i]];       // 1000 100 1000 10 100 1 5
                                      // now check i and i+1;
            else 
            { 
                ans += m[s[i]];
            }
        }
        
        return ans;
    }
};