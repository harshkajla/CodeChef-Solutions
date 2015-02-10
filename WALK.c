#include<stdio.h>
#define gc() getchar_unlocked()
#define read_int(n) n=0; c=gc();while(c<'0' || c>'9')c=gc();while(c>='0' && c<='9'){n= (n<<3)+(n<<1)+c-48;c=gc();}
int main()
{
	int t,temp,i,x,n;char c;
 
	scanf("%d",&t);
 
	while(t--)
	{
		read_int(n);
 
		temp=0;
		for(i=0;i<n;i++)
		{
			read_int(x);
			x+=i;
			temp = temp>x?temp:x;
		}
 
		printf("%d\n",temp);
 
	}
 
	return 0;
}
