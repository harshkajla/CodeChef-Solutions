#include<stdio.h>
int main()
{
	int n,i,j,q,k,count,found;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		count=0;
		for(i=0;i<n;i++)
		{
			found=0;
			for(j=i;j<n;j++)
			{
				if(a[j]==k)found=1;
				if(a[j]<k)
					break;
				else
				{
					if(found)
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
