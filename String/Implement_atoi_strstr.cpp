// What is the difference between stoi and atoi?
// First, atoi() converts C strings (null-terminated character arrays) to an integer,
// while stoi() converts the C++ string to an integer. 
//Second, the atoi() function will silently fail if the string is not convertible 
//to an int , while the stoi() function will simply throw an exception.

// In the question we have to handle four cases-->

// 1. discards all leading whitespaces
// 2. sign of the number
// 3. if overflow then simply return -2^31
// 4. invalid input
// 5. if fisrt sequence is not numeric then simply return 0
// 6. if we have word after a numeric value then simply return integer part