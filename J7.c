#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	long int wire, paper;
	float vol,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&wire,&paper);
		h=wire-sqrt(wire*wire-24*paper);
		h/=12.0;
		vol=paper*h/2.0 + h*h*h - h*h*wire/4.0;
		printf("%.2f\n",vol);
	}
}
