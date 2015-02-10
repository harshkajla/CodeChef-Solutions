#include<stdio.h>
char str[100001];
int primes[100001];
int seive[100001];
int count;
int palin(char* str, int i1, int i2)
{
	int f=0;
	while(i1<=i2 && f==0)
	{
		f=!(str[i1]==str[i2]);
		i1++;i2--;
	}
	return 1-f;
}
void seiv()
{
	int i,j;
	for(i=2;i<=100000;i++)
	{
		seive[i]=0;
	}
	for(i=2;i<=316;i++)
	{
		if(!seive[i])
		for(j=i*i;j<=100000;j+=i)
		{
			seive[j]=1;
		}
	}
	count=0;
	for(i=2;i<=100000;i++)
	{
		if(!seive[i])
		{
			primes[count++]=i;
		}
	}
}
int main()
{
	int t,l,j,palinc,i;
	char c1;
	scanf("%d",&t);
	seiv();
	while(t--)
	{
		scanf("%s",str);
		l=strlen(str);
		palinc=0;
		for(i=0;i<l;i++)
		{
			c1=str[i];
			j=0;
			while(j<count &&(i+primes[j]-1)<l)
			{
				if(str[i+primes[j]-1]!=c1)
				{
					j++;
					continue;
				}
				palinc+=palin(str,i,i+primes[j]-1);
				j++;
			}
		}
		printf("%d\n",palinc);
	}
}
