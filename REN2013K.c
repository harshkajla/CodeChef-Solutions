#include<stdio.h>
int main()
{
	int t;
	long long int x,y,n,diff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		diff=y-x+1;
		printf("%lld\n",(diff*(diff-1))/2);
	}
	return 0;
}
