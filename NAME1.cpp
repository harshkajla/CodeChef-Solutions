#include<stdio.h>
char a[40001],b[40001];
int count[256];
int c1[256];
int main()
{
	int t,i,n,f;
	char c;
	scanf("%d",&t);
	
	while(t--)
	{
		for(i=0;i<256;i++)count[i]=c1[i]=0;
		
		scanf("%s %s",a,b);
		
		for(i=0;a[i];i++)
		c1[a[i]]++;
		
		for(i=0;b[i];i++)
		c1[b[i]]++;
		
		scanf("%d",&n);
		getchar();
		
		f=0;
		for(i=0;i<n;)
		{
			c=getchar();
			if(c=='\n')i++;
			else count[c]++;
			
			if(count[c]>c1[c])
			f=1;
		}
		
		if(f)
		printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
}
