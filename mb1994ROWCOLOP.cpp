#include<stdio.h>
#include<algorithm>
using namespace std;
int index[10001];
int main()
{
	int t,n,k,s,i,x,sum1,sum2,j,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&s);
		int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			index[i]=i+1;
		}
		/*
		sum1=sum2=0;
		//algo 1:
		for(i=0;i<n;i++)
		{
			sum1+=(i<=k)*a[i]*a[i];
			sum2+=(i<=k)*a[n-i-1]*a[n-i-1];
		}
		if(sum1<sum2)
		{
			for(i=0;i<n;i++)
				printf("%d ",i+1);
			printf("\n");
		}
		else
		{
			for(i=0;i<n;i++)
			{
				printf("%d ",n-i);
			}
			printf("\n");
		}*/
		//sort all in descending order:
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				//desc order:
				if(a[i]>a[j])
				{
					temp=a[i];a[i]=a[j];a[j]=temp;
					temp=index[i];index[i]=index[j];index[j]=temp;
				}
			}
		}
/*
		//sort first k in ascending order:
		for(i=0;i<k;i++)
		{
			for(j=i+1;j<k;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];a[i]=a[j];a[j]=temp;
					temp=index[i];index[i]=index[j];index[j]=temp;
				}
			}
		}*/
		if(n>=50){
		for(i=0;i<50;i++)
		{
			for(j=i+1;j<50;j++)
			{
				//desc order:
				if(a[i]<a[j])
				{
					temp=a[i];a[i]=a[j];a[j]=temp;
					temp=index[i];index[i]=index[j];index[j]=temp;
				}
			}
		}}
		for(i=0;i<n;i++)
		{
			printf("%d ",index[i]);
		}printf("\n");
/*
		for(i=1;i<=n;i+=2)
			printf("%d ",i);
		for(i=2;i<=n;i+=2)
		{
			printf("%d ",i);
		}
		printf("\n");
		*/
	}return 0;
}
