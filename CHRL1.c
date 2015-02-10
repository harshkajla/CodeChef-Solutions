#include<stdio.h>
struct orange{
long long int cost;
long long int weight;
};
typedef struct orange orange;
void sort(orange* arr, int n)
{
	int i,j;
	orange temp;
	//ascending order
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j].cost<arr[i].cost)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main()
{
	int t,n,i;
	long long int k,maxWeight,remAmt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		orange arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&arr[i].cost,&arr[i].weight);
		}
		sort(arr,n);
		maxWeight=0;remAmt=k;
		for(i=0;i<n;i++)
		{
			if(arr[i].cost<=remAmt)
			{
				remAmt-=arr[i].cost;
				maxWeight+=arr[i].weight;
			}
		}
		printf("%lld\n",maxWeight);
	}
	return 0;
}
