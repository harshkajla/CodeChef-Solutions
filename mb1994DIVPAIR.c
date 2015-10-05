#include<stdio.h>
int main()
{
	int i,j,n,m,count=0,countZ=0,first,modV;
	scanf("%d%d",&n,&m);
	int p[n][m],a[n][m],mods[n][m];
	int rowmods[n],colmods[m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			mods[i][j]=p[i][j]-a[i][j]%p[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mods[i][j]!=0 && a[i][j]!=0)
			{
				while(j<m-1 && mods[i][j]==mods[i][j+1])
				{
					j++;
				}
				count++;
			}
		}
	}
	printf("%d\n",count);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if( mods[i][j]!=0 && a[i][j]!=0)
			{
				first=j+1;
				modV=mods[i][j];
				while(j<m-1 && mods[i][j]==mods[i][j+1])
				{
					j++;
				}
				printf("%d %d %d %d %d\n",i+1,first,i+1,j+1,modV);
			}
		}
	}
	return 0;
}
