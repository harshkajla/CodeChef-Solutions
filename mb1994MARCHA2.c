#include<stdio.h>
int main()
{
	short int t,n,i;
	int min;
	long int res,frag;
	scanf("%hd",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%hd",&n);
		res=frag=0;
		while(n--)
		{
			scanf("%d",&min);
			res+=((min/30)+1)*10;
			frag+=((min/60)+1)*15;
		}
		if(res==frag)
		{printf("Case %hd: Respawn Frag %ld\n",i,res);}
		
		else if(res<frag)
		{printf("Case %hd: Respawn %ld\n",i,res);}
		else if(res>frag)
		{printf("Case %hd: Frag %ld\n",i,frag);}
	}
	return 0;
}
