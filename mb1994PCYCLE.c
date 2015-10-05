#include<stdio.h>
#include<math.h>
int main()
{
	short int t;long long int sum;
	long int min,mini,avg,n,i,temp;
	scanf("%hd",&t);
	while(t--)
	{
		sum=0;
		scanf("%ld",&n);
		long int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%ld",&arr[i]);
			sum+=arr[i];
		}
		avg=sum/n;
		min=100000;
		//finding element closest to avg
		for(i=0;i<n;i++)
		{
			temp=avg-arr[i];
			if(temp<0)temp=-temp;
			if(temp<min)
			{min=temp;
			mini=i;
			}
		}
		sum=0;
		//minimum element found
		for(i=0;i<n;i++)
		{
			//calculating difference sums
			sum+=abs(arr[i]-arr[mini]);
		}
		printf("%lld\n",sum);
	}
		return 0;
}
