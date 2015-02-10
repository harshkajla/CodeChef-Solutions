#include<stdio.h>
#include<algorithm>
using namespace std;
int a[101];
int main()
{
	int t,n,f,steps,i,pos,mini;
	scanf("%d",&t);
	while(t--)
	{
		f=0;
		int sum=0;
		scanf("%d",&n);
		scanf("%d",&a[0]);
		mini=a[0];sum=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",a+i);
			sum+=a[i];
			mini=min(mini,a[i]);
		}
		printf("%d\n",sum-n*mini);
	}
	return 0;
}
