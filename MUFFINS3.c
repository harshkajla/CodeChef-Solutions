#include<stdio.h>
int main()
{
	int t;long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		printf("%ld\n",1+(n/2));
	}
	return 0;
}
