#include<stdio.h>
int main()
{
	int n,temp,count,start,f,i,k=0;
	scanf("%d",&n);
	int a[n+1],visited[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		visited[i]=0;
	}
	start=1;
	count=0;
	temp=start;
	while(count<n)
	{
		f=0;
		while(!visited[start])
		{
			visited[start]=1;
			start=a[start];
			count++;
			f=1;
		}
		if(f==1)k++;
		while(visited[temp])
			temp++;
		start=temp;
	}
	printf("%d\n",k);
	for(i=1;i<=n;i++)visited[i]=0;
	count=0;start=1;
	start=1;
	count=0;
	temp=start;
	while(count<n)
	{
		f=0;
		while(!visited[start])
		{
			printf("%d ",start);
			visited[start]=1;
			start=a[start];
			count++;
			f=1;
		}if(f==1){printf("%d",start);printf("\n");}
		while(visited[temp])
			temp++;
		start=temp;
	}
	return 0;
}
