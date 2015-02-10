#include<stdio.h>
int main()
{
	int t,x,a1,a0,b1,b0,mini,temp,i,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		a1=a0=b1=b0=0;
		//couting num of bits in a
		temp=a;
		while(temp!=0)
		{
			a1+=temp&1;
			temp>>=1;
		}
		a0=n-a1;
		temp=b;
		while(temp!=0)
		{
			b1+=temp&1;
			temp>>=1;
		}
		b0=n-b1;
		//printf("a0=%d a1=%d\nb0=%d b1=%d\n",a0,a1,b0,b1);
		x=0;
		//while both nos still have 1s in their binary:
		while(a1 || b1)
		{
			if(a1&& b0)
			{
				//printf("a1b0\n");
				x=(x<<1)+1;
				//printf("x=%d\n",x);
				a1--;b0--;
			}
			else if(b1 && a0)
			{
				//printf("b1a0\n");
				x=(x<<1)+1;
				//printf("x=%d\n",x);
				b1--;a0--;
			}
			else
			{
				//printf("only 1s\n");
				x<<=1;
				//printf("x=%d\n",x);
				a1--;b1--;
			}
		}
		while(a0&&b0)
		{
			x<<=1;a0--;b0--;
		}
		printf("%d\n",x);
	}
	return 0;
}
