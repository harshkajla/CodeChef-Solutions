#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,k,sum,i,a[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		sum=0;
		if(k>(n/2))k=n-k;
		for(i=1;i<=n;i++)
		{
			if(i<=k)
			{
				sum-=a[i-1];
			}
			else sum+=a[i-1];
		}
		printf("%d\n",sum);
	}
	return 0;
}
