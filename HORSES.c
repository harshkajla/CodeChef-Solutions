#include<stdio.h>
int main()
{
	int t,n,i,j;
	long int temp,diff,tempDiff;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long int a[n];
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		//sorting
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j]<a[i])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		diff=a[1]-a[0];
		//traversing to find min diff
		for(i=0;i<n-1;i++)
		{
			tempDiff=a[i+1]-a[i];
			if(tempDiff<diff)
			{
				diff=tempDiff;
			}
		}
		printf("%d\n",diff);
	}
	return 0;
}
