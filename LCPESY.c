#include<stdio.h>
int main()
{
	int t,i,count,l1,l2;
	int c1[150];
	char s1[10001];
	char s2[10001];
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		for(i=0;i<150;i++)
			c1[i]=0;
		scanf("%s",s1);
		scanf("%s",s2);
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=0;i<l1;i++)
		{
			c1[s1[i]]++;
		}
		for(i=0;i<l2;i++)
		{
			if(c1[s2[i]])
			{
				count++;
				c1[s2[i]]--;
			}
		}
		printf("%d\n",count);
	}
}
