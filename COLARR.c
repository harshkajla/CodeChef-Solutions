#include<stdio.h>
int indexes[10000];
int main()
{
	short int t;
	int n,m,k,i,j,sum,count,x;
	scanf("%hd",&t);
	while(t--)
	{
		for(i=1;i<10000;i++)
			indexes[i]=i;
		scanf("%d%d%d",&n,&m,&k);
		int initColor[n+1];
		for(i=1;i<n+1;i++)
		{
			scanf("%d",&initColor[i]);
		}
		int profit[n+1][m+1];
		for(i=1;i<n+1;i++)
		{
			for(j=1;j<m+1;j++)
			{
				scanf("%d",&profit[i][j]);
			}
		}
		//store profit-cost for each cell's each color combination.
		//calculate the max(profit-cost) for each cell.
sum=0;
		int profit_minus_cost[n+1][m+1];int maxProfit[n+1];
		for(i=1;i<n+1;i++)
		{
			sum+=profit[i][initColor[i]];
			maxProfit[i]=0;
			for(j=1;j<m+1;j++)
			{
				scanf("%d",&x);
				profit_minus_cost[i][j]=profit[i][j]-x-profit[i][initColor[i]];
				if(profit_minus_cost[i][j]>maxProfit[i])
					maxProfit[i]=profit_minus_cost[i][j];
			}
			//printf("max profit for %d = %d\n",i,maxProfit[i]);
		}
		//sort the max(profit-cost) array to find the max value of k elements.
		sort(maxProfit, n);
		//find last k sums
		count=0;
		while(count<k)
		{
			sum+=maxProfit[n-count];
			count++;
		}
		printf("%d\n",sum);
	}
}
//nominal sort function
void sort(int* a,int size)
{int aux[size];
        int low,high;
        low=1;
        high=size;
  //calling actual sort function
        msort(a,low,high,aux);
}
//actual sort function
void msort(int* a, int low, int high,int* aux)
{
        int mid;
        if(high<=low)
        return;
        mid=(low+high)/2;
        msort(a,low,mid,aux);
        msort(a,mid+1,high,aux);
        merge(a,low,mid,high,aux);
}
//merge function
void merge(int* a, int low, int mid, int high,int* aux)
{
        int i,j,k;     //aux[] is auxillary array that stores a temporarily.
  //first storing a into aux
        for(i=low;i<high+1;i++)
        aux[i]=a[i];
  //merge-sorting
        j=low;
        k=mid+1;
        for(i=low;i<=high;i++)
        {
                if(j>mid) {a[i]=aux[k];indexes[i]=indexes[k];k++;}
                else if(k>high) {a[i]=aux[j];indexes[i]=indexes[j];j++;}
                else if(aux[j]<=aux[k]) {a[i]=aux[j];indexes[i]=indexes[j];j++;}
                else if(aux[j]>aux[k]) {a[i]=aux[k];indexes[i]=indexes[k];k++;}
        }
}
