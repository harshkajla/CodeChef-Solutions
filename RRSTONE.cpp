#include<stdio.h>
long long int a[100001];
int main()
{
	long long int n,k,i,min,max;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		if(i==0)max=min=a[i];
		if(a[i]>max)max=a[i];
		else if(a[i]<min)min=a[i];
	}
	if(k==0)
	{for(i=0;i<n;i++)printf("%lld ",a[i]);printf("\n");}
	else if(k&1)//odd
	{
		for(i=0;i<n;i++)
		{
			printf("%lld ",max-a[i]);
		}printf("\n");
	}
	else{
		for(i=0;i<n;i++)
		{
			printf("%lld ",a[i]-min);
		}printf("\n");}
	return 0;
}
