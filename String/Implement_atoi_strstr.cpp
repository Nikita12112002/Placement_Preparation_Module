// What is the difference between stoi and atoi?
// First, atoi() converts C strings (null-terminated character arrays) to an integer,
// while stoi() converts the C++ string to an integer.
// Second, the atoi() function will silently fail if the string is not convertible
// to an int , while the stoi() function will simply throw an exception.

// In the question we have to handle four cases-->

// 1. discards all leading whitespaces
// 2. sign of the number
// 3. if overflow then simply return -2^31
// 4. invalid input
// 5. if fisrt sequence is not numeric then simply return 0
// 6. if we have word after a numeric value then simply return integer part

class Solution
{
public:
    int myAtoi(string s)
    {

        int res = 0;
        int i = 0;
        int sign = 1;

        while (i < s.size() && s[i] == ' ')
            i++; // ignore leading white space

        if (s[i] == '-' || s[i] == '+') // check if number positve or negative
        {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        // now iterate across digits if any
        // should only be in range 0-9
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) // traverse string till nondigit not found or string ends
        {
            int digit = (s[i] - '0') * sign;
            if (sign == 1 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)))
                return INT_MAX; // check for overflow
            if (sign == -1 && (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < INT_MIN % 10)))
                return INT_MIN; // check for underflow

            res = res * 10 + digit; // update res
            i++;
        }

        return res;
    }
};