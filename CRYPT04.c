#include<stdio.h>
#include<math.h>
int main()
{
	long int n,temp;
	int ex;
	
	while(1)
	{
		scanf("%ld",&n);
		
		if(n==0)
		return 0;
		ex=(int)(log(n)/log(2));
		temp=(long int)pow(2,ex);
		if(temp==n)
		{
			printf("%ld\n",n);continue;
		}
		printf("%ld\n",(n-temp)<<1);
	}
	return 0;
}
