#include<stdio.h>
int main()
{
	int t,ht1,ht2,mt1,mt2,st1,st2;
	long int t1,t2,dt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&ht1,&mt1,&st1);
		scanf("%d%d%d",&ht2,&mt2,&st2);
		t1=ht1*3600+mt1*60+st1;
		t2=ht2*3600+mt2*60+st2;
		dt=t2-t1;
		dt=dt%400;
		if(dt>=0 && dt<=99)
		printf("S\n");
		else if(dt>=100 && dt<=199)
		printf("C\n");
		else if(dt>=200 && dt<=299)
		printf("S\n");
		else
		printf("C\n");
	}
	return 0;
}
