class Solution {
public:
    int minMovesToMakePalindrome(string s) {

     //concept-->either make left half equal to right half or right half equal to left half    
        int n = s.length();
        
        int left=0,right=n-1,ans=0;
        
        while(left<right)
        {
            int l=left , r=right;
            
            while(s[l]!=s[r]) // jab tk equal element mil jata tab tk r ko decrement krtay jaao.
            {
                r--;   
            }
            
            if(l==r)
            {
                swap(s[r],s[r+1]);
                ans++;
                continue;
            }
            
            else
            {
                while(r<right)
                {
                    swap(s[r],s[r+1]);
                    ans++;
                    r++;
                        
                }
            }
            left++ ;
            right--;
        }
        return ans;
    }
};