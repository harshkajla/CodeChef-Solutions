#include<stdio.h>
int main()
{
	int t;
	long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%2!=0)
		{
			printf("2\n");
			continue;
		}
		printf("%lld\n",(2*n)&(-2*n));
	}
	return 0;
}
