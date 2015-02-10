#include<stdio.h>
int minI[1000001];
int min(int t1,int t2)
{
	return t1>t2?t2:t1;
}
int max(int t1, int t2)
{
	return t1>t2?t1:t2;
}
int main()
{
	int n,k,tempMin,minT,i,x,found;
	scanf("%d%d",&n,&k);
	for(i=0;i<1000001;i++)
		minI[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(minI[x]==0)
			minI[x]=min(i,n-i+1);
		else
			minI[x]=min(minI[x],min(i,n-i+1));
	}
	minT=10000000;found=0;
	for(i=1;i<1000001;i++)
	{
		if(i>=k)break;
		if(minI[i] && minI[k-i] && i!=(k-i))
		{
			found=1;
			tempMin=max(minI[i],minI[k-i]);
			minT=min(minT,tempMin);
		}
	}
	if(!found)printf("-1\n");
	else
	printf("%d\n",minT);
	return 0;
}
