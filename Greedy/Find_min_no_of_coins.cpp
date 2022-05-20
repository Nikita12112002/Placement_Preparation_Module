int findMinimumCoins(int amount) 
{
    // Write your code here
	
	int a[9]={1,2,5,10,20,50,100,500,1000};
	int coins=0;
	for(int i=8 ; i>=0 ;i--)
	{
		while(amount>=a[i])
		{
			amount=amount-a[i];
			coins++;
		}
			
	}
	return coins;
}
