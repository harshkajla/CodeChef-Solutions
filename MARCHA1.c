#include<stdio.h>
int main()
{
	int t,comb,bitnum,n,m,i,k,sum,f;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		comb=(1<<n)-1;
		bitnum=0;
		f=0;
		for(i=0;i<=comb;i++)
		{
			k=i;bitnum=0;sum=0;
			while(k!=0)
			{
				if(k&1)
				{
					sum+=a[bitnum];
					if(sum==m){f=1;break;}
					if(sum>m)break;
				}
				bitnum++;
				k>>=1;
			}
			if(f==1){printf("Yes\n");break;}
		}
		if(f==0)printf("No\n");
	}
	return 0;
}
