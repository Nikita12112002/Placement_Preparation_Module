//Problem Statement-->

//You are given a three integers 'X', 'N', and 'M'. 
//Your task is to find ('X' ^ 'N') % 'M'. 
//A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.

//TC:O(logn)

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	 long long int copy=x;
	long long int ans=1;
	
	while(n>0)
	{
		if(n%2!=0)
		{
			ans=(ans*(copy%m))%m;
			
			n=n-1;
		}
		
		else
		{
			copy=((copy%m)*(copy%m))%m;
			n=n/2;
		}
	}
	
	
	return ans%m;
}