#include<stdio.h>
int main()
{
	int t,jewels;char c;int i;
	int ascii[123]={0};
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		jewels=0;
		while((c=getchar())!='\n')
		{
			ascii[c]=1;
		}
		while((c=getchar())!='\n')
		{
			if(ascii[c]==1)jewels++;
		}
		printf("%d\n",jewels);
		for(i=0;i<123;i++)ascii[i]=0;
	}
	return 0;
}
