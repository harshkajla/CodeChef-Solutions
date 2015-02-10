#include<stdio.h>
inline long long int mult(long long int a, long long int b)
{
	long long int ans=a,res=0;
	if(b==0)return 0;
	if(b==1)return 1;
	while(b!=1)
	{
		if(b&1)res+=a;
		a<<=1;
		b>>=1;
	}
	return res+a;
}
int main()
{
	int t,a;
	long long int n,k,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&k,&m);
		if(k==1){printf("%lld\n",n);continue;}
		if(n%k!=0)//not a multiple of k
		{
			if(m%2==0)printf("%lld\n",n);
			else printf("%lld\n",n*k);
			continue;
		}
		else
		{
			a=0;
			while(a<m && n%k==0)
			{
				n/=k;
				a++;
			}
			if(a==m)
				printf("%lld\n",n);
			else
			{
				if((m-a)%2==0)printf("%lld\n",n);
				else printf("%lld\n",n*k);
			}
		}
	}
	return 0;
}
