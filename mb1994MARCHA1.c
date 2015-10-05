#include<stdio.h>
#include<math.h>
int check(long int);
int main()
{
	short int t;long int n,sroot,i,sum;
	scanf("%hd",&t);
	while(t--)
	{
		scanf("%ld",&n);
		sroot=sqrt(n);
		sum=0;
		if(n%2!=0)
		{
			for(i=1;i<=sroot;i+=2)
			{
				if(n%i==0)
				sum+=check(i)+check(n/i);
			}
			
			printf("%ld\n",sum);continue;
		}
		for(i=1;i<=sroot;i++)
		{
			if(n%i==0)
			sum+=check(i)+check(n/i);
		}
		printf("%ld\n",sum);
	}
	return 0;
}
int check(long int n)
{
	int r;
	while(n!=0)
	{r=n%10;n/=10;
	if(r==4 || r==7)return 1;
	}
	return 0;
}
