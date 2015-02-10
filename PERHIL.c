#include<stdio.h>
int main()
{
	int t,f;
	long int s,i,j;
	long long int sq,temp;
	scanf("%d",&t);
	while(t--)
	{f=0;
		scanf("%ld",&s);
    
		i=1;j=s-1;
		sq=s*s;
		while(j>=i)
		{
			temp=i*i+j*j;
			if(temp==sq)
			{f=1;break;}
			else if(temp>sq)
			j--;
			else if(temp<sq)
			i++;
		}
	if(f==1)
	printf("PERFECT\n");
	else
	printf("IMPERFECT\n");
	}
	return 0;
}
