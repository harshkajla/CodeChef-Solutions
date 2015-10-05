#include<stdio.h>
int main()
{
	int n,i,check,init,count,val;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	count=0;init=0;check=0;
while(check<n){
	init=0;
	val=a[init];
	
	for(i=0;i<n;i++)
	{
		if(val==0 && a[i]!=0)
			{init=i;val=a[init];}
		if(a[i]!=0 && a[i]>=val)
		{
			init=i;val=a[i];
			a[i]=0;
			check++;
		}
	}
	count++;
}
printf("%d\n",count);
return 0;
}
