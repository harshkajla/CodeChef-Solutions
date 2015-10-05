#include<stdio.h>
#include<math.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int main()
{
	int n,a,b,maxi,mini,length;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		mini=min(a,b);
		maxi=max(a,b);
		length=0;
		while(mini!=maxi)
		{
			if(mini>maxi)
				mini/=2;
			else
				maxi/=2;
			length++;
		}
		printf("%d\n",length);
	}
	return 0;
}
