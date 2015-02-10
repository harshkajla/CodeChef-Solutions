#include<stdio.h>
#include<math.h>
#define d(a,b,c,f) sqrt((a-c)*(a-c)+(f-b)*(f-b))
int main()
{
	float range;
	int i,t,connect=0;
	float x[3],y[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f",&range);
		for(i=0;i<3;i++)
		scanf("%f%f",&x[i],&y[i]);
		//1st person connect check
		if(d(x[0],y[0],x[1],y[1])<=range)
			connect++;
		else
		{
			if(d(x[0],y[0],x[2],y[2])<=range && d(x[1],y[1],x[2],y[2])<=range)
				connect++;
			else {printf("no\n");continue;}
		}
		if(d(x[0],y[0],x[2],y[2])<=range)
			connect++;
		else
		{
			if(d(x[0],y[0],x[1],y[1])<=range && d(x[1],y[1],x[2],y[2])<=range)
				connect++;
			else {printf("no\n");continue;}
		}
		//third person only
		if(d(x[1],y[1],x[2],y[2])<=range)
			connect++;
		else
		{
			if(d(x[0],y[0],x[1],y[1])<=range && d(x[0],y[0],x[2],y[2])<=range)
				connect++;
			else {printf("no\n");continue;}
		}
		printf("yes\n");
	}
	return 0;
}
