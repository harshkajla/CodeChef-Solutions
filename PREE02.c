#include<stdio.h>
#include<math.h>
int is_special(long int);
int main()
{int t;
long int count,n,i,sroot;
	scanf("%d",&t);
	while(t--)
	{count=0;
		scanf("%ld",&n);
		sroot=(long int)sqrt(n);
		for(i=1;i<=sroot;i++)
		{
			if(n%i==0)
			count+=is_special(i)+is_special(n/i);
		}
		if(sroot*sroot==n)
		count-=is_special(sroot);
		printf("%ld\n",count);
	}
	return 0;
}
int is_special(long int n)
{
	int r;
	while(n!=0)
	{
		r=n%10;n/=10;
		if(r==3 || r==5 || r==6)return 1;
	}
	return 0;
}
