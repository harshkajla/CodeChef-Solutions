#include<stdio.h>
#define gc() getchar_unlocked()
#define read_int(n) n=0; c=gc();while(c<'0' || c>'9')c=gc();while(c>='0' && c<='9'){n= (n<<3)+(n<<1)+c-48;c=gc();}
int main()
{
	short int t;
	int i,n,x;
	char c;
	long long int c2,c3;
	read_int(t);
	while(t--)
	{
		read_int(n);
		c2=c3=0;
		i=n;
		
		while(i--)
		{
			read_int(x);
			c2+=(x==2);
			c3+=(x>=3);
		}
		printf("%lld\n",c3*(c3+(c2<<1)-1)>>1);
	}
	return 0;
}
