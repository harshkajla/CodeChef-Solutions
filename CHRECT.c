#include<stdio.h>
int main()
{
	short int t,n,m,k;
	scanf("%hd",&t);
	while(t--)
	{
		scanf("%hd%hd%hd",&n,&m,&k);
		if((m+n)==2 || (m+n)==3)
		{printf("0\n");continue;}
		if(n==1 || m==1)
		{
			printf("%hd\n",k);
			continue;
		}
		printf("%hd\n",(k+1)/2);
	}
	return 0;
}
