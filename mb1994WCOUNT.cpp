#include<stdio.h>
int findp(long long k)
{
	int pow=0,ans=0;
	long long val=1;
	while(true)
	{
		if(val>=k)
			return ans;
		ans=pow;
		val<<=1;pow++;
	}
	return ans;
}
int main()
{
	int t,n,x;
	long long k;
	long double del;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		if(k==1)
		{
			printf("%.7lf\n",n/2.0);
			continue;
		}
		x=findp(k+1);
		//printf("x=%d\n",x);
		long long a=1;
		a<<=x;
		del=k+1-a;
		del=2*del-1.0;
		long double num=del;
		num*=n;
		long double den=a*2.0;
		
		printf("%.7Lf\n",num/den);
	}
	return 0;
}
