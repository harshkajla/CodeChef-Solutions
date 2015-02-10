#include<stdio.h>
int main()
{
	long long int a;
	scanf("%lld",&a);
	a=a%6;
	if(a==1 || a==0 || a==3)
	{
		printf("yes\n");
	}
	else printf("no\n");
	return 0;
}
