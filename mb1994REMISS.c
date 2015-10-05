#include<stdio.h>
int main()
{
	int t,n,m,q,i,j,count,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		int a[n+1][m+1],b[n+1][m+1],similar[n+1][m+1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i][1]);
			similar[i][0]=0;
			similar[i][1]=(a[i][1]==b[i][1]);
			for(j=2;j<=m;j++)
			{
				scanf("%d",&b[i][j]);
				similar[i][j]=similar[i][j-1]+(a[i][j]==b[i][j]);
			}
		}
		for(i=0;i<q;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			count=0;
			for(j=x1;j<=x2;j++)
			{
				count+=similar[j][y2]-similar[j][y1-1];
			}
			printf("%d\n",count);
		}
	}
	return 0;
}
