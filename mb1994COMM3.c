#include<stdio.h>
int main()
{
	int t,n,i;
	long int b;
	long long int sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%ld",&n,&b);
		for(i=1;i<=n;i++)
		{
			sum+=i;
			if(sum==b)
			sum-=1;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
