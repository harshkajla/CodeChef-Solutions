#include<stdio.h>
long long int gcd(long long int a, long long int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t;
	long long int numCoco,minSize,minRipe,i,acut,rcut,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&numCoco,&minSize,&minRipe);
		acut=rcut=0;
		long long int size[numCoco],ripe[numCoco];
		for(i=0;i<numCoco;i++)
		{
			scanf("%lld%lld",&size[i],&ripe[i]);
			rcut+=(size[i]>minSize || ripe[i]>minRipe);
		}
		scanf("%lld",&acut);
		x=gcd(acut,rcut);
		rcut/=x;
		acut/=x;
		printf("%lld/%lld\n",rcut,acut);
	}
	return 0;
}
