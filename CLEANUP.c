#include<stdio.h>
int jobs[1001];
int main()
{
		int t,i,x,n,m,flag;
		scanf("%d",&t);
		while(t--)
		{
			flag=1;
			scanf("%d%d",&n,&m);
			for(i=0;i<m;i++)
			{
				scanf("%d",&x);
				jobs[x]=1;
			}
			for(i=1;i<=n;i++)
			{
				if(jobs[i]==0)
				{
					if(flag==1){
					jobs[i]=1;
					printf("%d ",i);
					flag=0;}
					else flag=1;
				}
			}
			printf("\n");
			for(i=1;i<=n;i++)
			{
				if(jobs[i]==0)
				{
					printf("%d ",i);
				}
				else jobs[i]=0;
			}
			printf("\n");
		}
		return 0;
}
