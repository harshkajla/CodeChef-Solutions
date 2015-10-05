#include<stdio.h>
#include<limits.h>
int pows[10000];
int h[200001];
int dp[200001];
int main()
{
	int n,c,tmp,ind;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	scanf("%d",&h[i]);
	
	c=0;
	for(int i=0;;i++)
	{
		tmp=1<<i;
		if(tmp>n)break;
		
		pows[c++]=tmp;
	}
	
	dp[0]=0;
	for(int i=1;i<n;i++)
	dp[i]=INT_MAX;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<c;j++)
		{
			ind=i-pows[j];
			if(ind<0)break;
			
			tmp=h[i]-h[ind];
			if(tmp<0)tmp=-tmp;
			
			tmp+=dp[ind];
			if(dp[i]>tmp)dp[i]=tmp;
		}
	}
	printf("%d\n",dp[n-1]);
}
