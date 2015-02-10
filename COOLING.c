#include<stdio.h>
void sort(int* a, int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];a[j]=temp;
			}
		}
	}
}
int main()
{
	int t,i,wtIndex,f,count,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int pie[n],wt[n];
		for(i=0;i<n;i++)
		scanf("%d",&pie[i]);
		for(i=0;i<n;i++)
		scanf("%d",&wt[i]);
		sort(pie,n);
		sort(wt,n);
		wtIndex=0;f=0;count=0;
		for(i=0;i<n;i++)
		{
			if(wtIndex==n)break;
			while(wt[wtIndex]<pie[i])
			{
				wtIndex++;
				if(wtIndex==n)
				{f=1;break;}
				
			}if(f==0){count++;wtIndex++;}else break;
		}
		printf("%d\n",count);
	}
	return 0;
}
