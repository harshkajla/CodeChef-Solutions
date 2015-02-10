/*finding the best plan:
key items:
1.activation charge
2.number of months
3.price per minute
best plan selection:
1.find:  (activation+ months*minutesTalkedPerMonth*pricePerMinute)/months
2.find index of min of these values
that is the answer.
*/
#include<stdio.h>
int main()
{
	int t,minutesTalked,n,minIndex,noOfMonths,activation,i;
	float min,defaultRate,pricePerMin,val;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%d%d",&defaultRate,&minutesTalked,&n);
		min = defaultRate*minutesTalked;
		minIndex=0;
		//n plans
		for(i=1;i<=n;i++)
		{
			scanf("%d%f%d",&noOfMonths,&pricePerMin,&activation);
			val=activation + noOfMonths*minutesTalked*pricePerMin;
			val/=(noOfMonths+0.0d);
			if(val<min)
			{
				min=val;
				minIndex=i;
			}
		}
		printf("%d\n",minIndex);
	}
	return 0;
}
