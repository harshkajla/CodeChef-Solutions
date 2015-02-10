#include<stdio.h>
#include<math.h>
int main()
{
	long int t,n;
	scanf("%ld",&t);
	
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",(long int)(pow(2,(long int)(log(n)/log(2)))));
	}
	return 0;
	}
