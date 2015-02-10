#include<stdio.h>
int main()
{
	int n,count,a,b,c,dd1,dd2,dd3,d1,d2,d3,x1,x2,x3,y1,y2,y3;
	scanf("%d",&n);
count=0;
	while(n--)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		d1=x1-x2;
		d2=x2-x3;
		d3=x3-x1;
		dd1=y1-y2;
		dd2=y2-y3;
		dd3=y3-y1;
		a=d1*d1+dd1*dd1;
		b=d2*d2+dd2*dd2;
		c=d3*d3+dd3*dd3;
		if(a==(b+c) || b==(a+c) || c==(a+b))
			count++;
	}
	printf("%d\n",count);
	return 0;
}
