#include<stdio.h>
int row[314160];
int col[314160];
int main()
{
	int n,q,i,x,maxr,maxc;
	char str[100];
	maxr=maxc=0;
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%s%d%d",str, &i,&x);
		//printf("str=%s..\n",str);
		if(str[0]=='R')
		{
			row[i]+=x;
		}
		else col[i]+=x;
	}
	for(i=1;i<=314159;i++)
	{
		if(row[i]>maxr)
		maxr=row[i];
		if(col[i]>maxc)
		maxc=col[i];
	}
	printf("%d\n",maxr+maxc);
	return 0;
}
