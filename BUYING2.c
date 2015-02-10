#include<stdio.h>
int main()
{
	int t,i,sum,diff,n,k,sweets,f;
	scanf("%d",&t);
	while(t--)
	{
		f=0;
		scanf("%d%d",&n,&k);
		int amt[n];
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&amt[i]);
			sum+=amt[i];
		}
		sweets=sum/k;
		diff=(sum-sweets*k);
		for(i=0;i<n;i++)
		{
			if(amt[i]<=diff)
			{
				f=1;break;
			}
		}
		if(f==1)printf("-1\n");
		else printf("%d\n",sweets);
	}
	return 0;
}
