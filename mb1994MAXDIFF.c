#include<stdio.h>
int main()
{
	int t,x1,x2,x11,x22,y1,y2,y11,y22;
	int arr[1002][1002],i,j,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d%d%d",&x11,&y11,&x22,&y22);
	for(i=0;i<=1001;i++)
	{for(j=0;j<=1001;j++)
	{
		arr[i][j]=1;
	}}
	//printf("%d\n",count);
		for(i=y1;i<=y2-1;i++)
		{//printf("i=%d:\n",i);
			for(j=x1;j<=x2-1;j++)
			{//printf("j=%d\n",j);
				arr[i][j]=0;
			}
		}
		//printf("area1=%d\n",count);count=0;
		for(i=y11;i<=y22-1;i++)
		{
			for(j=x11;j<=x22-1;j++)
			{
				arr[i][j]=0;
			}
		}
		for(i=0;i<=1001;i++)
		{
			for(j=0;j<=1001;j++)
			{
				if(arr[i][j]==0)count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
