#include<stdio.h>
int a[100001];
int main()
{
	int n,m,i,index,x,pos;
	char ch;
	
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	index=1;
	getchar();
	for(i=0;i<m;i++)
	{
		scanf("%c %d",&ch,&x);
		//putchar(ch);puts("");
		
		getchar();
		
		if(ch=='C')
		{
			//clockwise rotation..
			index=index+n-x;
			
			if(index>n)index-=n;
			
			//printf("c..index=%d\n",index);
		}
		
		else if(ch=='A')
		{
			//anticlockwise rotation..
			index=index+x-n;
			
			if(index<=0)index+=n;
			else if(index>n)index-=n;
			
			//printf("A..index=%d\n",index);
		}
		
		else
		{
			pos=x-index+1;
			if(pos>n)pos-=n;
			else if(pos<=0)pos+=n;
			
			printf("%d\n",a[pos]);
		}
	}
	
	return 0;
}
