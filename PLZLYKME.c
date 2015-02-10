#include <stdio.h>
#include<math.h>
int main(void) {
	
	int t;
	long long int l,d,s,c;
	double q,logval;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&l,&d,&s,&c);
		
		q = l/(s+0.0d);
		logval = log(q)/log(1+c);
		
		if(logval<=(d-1.0d))
		printf("ALIVE AND KICKING\n");
		
		else
		printf("DEAD AND ROTTING\n");
		
	}
	return 0;
}
