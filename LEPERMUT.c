#include<stdio.h>
int main()
{
	int t,n,a[101],yes,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		yes=1;
		for(i=0;i<n;i++)scanf("%d",a+i);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j] && j!=(i+1))
				{
					yes=0;break;
				}
			}if(yes==0)break;
		}
		if(yes)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
