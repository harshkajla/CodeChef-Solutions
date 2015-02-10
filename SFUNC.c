#include <stdio.h>
long long int gcd(long long int, long long int);
int main() {
	
	long long int n,k,m, sum=0;
	long long int i,j, prod;
	
	scanf("%lld%lld%lld",&n,&k,&m);
	
	for(i=1;i<n;i++)
	{
		if(gcd(i,n)==1)
		{		prod=1;
		for(j=0;j<k;j++)
		{
			prod=(prod*i)%m;
		}
		sum=(sum+prod)%m;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
long long int gcd(long long int i, long long int n)
{
	if(i==1)
	return 1;
	
	if(i==0)return n;
	
	if(i>n)
	return gcd(n,i);
	
	else
	return gcd(n%i,i);
}
