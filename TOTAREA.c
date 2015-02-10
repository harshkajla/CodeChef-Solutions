#include<stdio.h>
int main()
{
	int t,n;
	int area=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		area=n*n*17;
		printf("%f\n",(float)area/6);
	}
	return 0;
}
