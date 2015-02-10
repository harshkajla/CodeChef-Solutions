#include<stdio.h>
#include<algorithm>
using namespace std;
long long int a[100001];
int main()
{
	long long int n,d,i,front,back,ans;
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
		scanf("%lld",a+i);
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		for(;i<n-1;i++)
		{
			if(a[i+1]<=(a[i]+d))
			{
				ans++;i++;break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
