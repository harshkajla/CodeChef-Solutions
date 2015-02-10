#include<stdio.h>
#include<string.h>
char with[51][51];
char found[51][51];
int yes[51];
int main()
{
	int n,k,i,j;
	scanf("%d%d",&k,&n);
	for(i=0;i<k;i++)
	{
		scanf("%s",with[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",found[i]);
		if(strlen(found[i])>=47)yes[i]=1;
	}
	for(i=0;i<n;i++)
	{
		if(yes[i]==0)
		for(j=0;j<k;j++)
		{
			if(strstr(found[i],with[j])!=NULL)
			{
				yes[i]=1;break;
			}
		}
	}
	for(i=0;i<n;i++)	{
		if(yes[i])printf("Good\n");
		else printf("Bad\n");
	}
	return 0;
}
