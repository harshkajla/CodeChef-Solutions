#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,k,i,j,count=0,sum,temp;
	
	scanf("%lld%lld",&n,&k);
	long long int a[n];
	
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	
	for(i=0;i<n;i++)
	{
		sum=0;temp=0;
		for(j=i;j<n;j++)
		{
			temp+=k;
			sum+=a[j];
			if(sum>=temp)
			count++;
		}
	}
	
	printf("%lld\n",count);
	return 0;
}
