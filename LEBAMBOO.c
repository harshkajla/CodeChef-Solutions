#include<stdio.h>
int main()
{
	int t,f,steps,flag,diff,n,i,hsum,dsum;
	int h[50],d[50];
	scanf("%d",&t);
	while(t--)
	{i=0;hsum=0;dsum=0;f=0;
		scanf("%d",&n);
		//accepting
		while(i<n)
		{
			scanf("%d",&h[i]);
			i++;
		}
		i=0;
		while(i<n)
		{
			scanf("%d",&d[i]);
			i++;
		}
		
		//n==1 case
		if(n==1)
		{
			if(h[0]==d[0])
			{printf("0\n");continue;}
			if(d[0]>h[0])
			{printf("-1\n");continue;}
			printf("%d\n",h[0]-d[0]);
			continue;
		}
		//summing up
		for(i=0;i<n;i++)
		{
			hsum+=h[i];
			dsum+=d[i];
		}
		//n==2 case
		if(n==2)
		{
			if((h[0]-d[0])!=(d[1]-h[1]))
			{printf("-1\n");continue;}
			diff=h[0]-d[0];
			if(diff<0)diff=-diff;
			printf("%d\n",diff);continue;
		}
		//remaining cases
		diff=dsum-hsum;
		if(diff<0){printf("-1\n");continue;}
		if(diff%(n-2)!=0)
		{printf("-1\n");continue;}
		steps=diff/(n-2);
		flag=steps%2;
		//checking individual differences
		for(i=0;i<n;i++)
		{
			diff=d[i]-h[i];
			if(diff<0)diff=-diff;
			if(diff>steps){printf("-1\n");f=1;break;}
			//checking diff
			if(flag==1 && diff%2!=1)
			{printf("-1\n");f=1;break;}
			if(flag==0 && diff%2!=0)
			{printf("-1\n");f=1;break;}
		}
		if(f==1)
		continue;
		printf("%d\n",steps);
	}
	return 0;
}
