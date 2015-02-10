#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,j,n,max,ind1,ind2,count,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n],dep[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<n;i++)
			scanf("%d",&dep[i]);
		sort(arr,arr+n);
		sort(dep,dep+n);
		count=0;ind1=0;ind2=0;max=0;
		while(ind1<n && ind2<n)
		{
			if(arr[ind1]<dep[ind2])
			{
				count++;ind1++;
			}
			else if(arr[ind1]>dep[ind2])
			{
				count--;ind2++;
			}
			else
			{
				ind2++;count--;
			}
			if(count>max)max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}
