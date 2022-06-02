class Solution {
public:
    string reverseWords(string s) {
        
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    int count_spaces=0;
    
        
    while (left <= right) 
    {
        char ch= s[left];
        if (ch != ' ') 
        {
            temp += ch;
            count_spaces=0;  // as soon as we will encounter a word we will do count=0 
        } 
        else if (ch == ' ')
        {
             count_spaces++;
            if (ans!="" && count_spaces<=1) // if there is single space b/w words add the word in ans
            {
                ans = temp + " " + ans;
                
            }
            else if(ans==""&&count_spaces<=1) // handles leading spaces
                ans = temp;
        
            temp = "";
        }
        left++;
    }
    
    //If not empty string then add to the result(Last word is added)
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    


    }
};