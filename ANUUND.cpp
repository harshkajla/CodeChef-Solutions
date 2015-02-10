#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
	int t,i,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",a+i);
		if(n==2)swap(a[0],a[1]);
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(i&1 &&i<n-1)
			{
				swap(a[i],a[i+1]);
			}
		}
		for(i=0;i<n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
