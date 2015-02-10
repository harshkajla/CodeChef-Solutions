#include<stdio.h>
int main()
{
	int t=10,a[42]={0},temp,i;
	while(t--)
	{
		//accepting
		for(i=0;i<10;i++)
		{
			scanf("%d",&temp);
			a[temp%42]=1;
		}
		//comparing
		
		for(i=1;i<42;i++)
		a[0]+=a[i];
		printf("%d\n",a[0]);
		for(i=0;i<42;i++)
		a[i]=0;
	}
	return 0;
}
