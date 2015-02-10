#include<stdio.h>
int main()
{int n1,n2,n3,sum,i,count=0;
    scanf("%d%d%d",&n1,&n2,&n3);
    sum=n1+n2+n3;int arr[sum];
    for(i=0;i<sum;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,sum);
    for(i=0;i<sum-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            i++;
            count++;
        }
    }
    printf("%d\n",count);
    for(i=0;i<sum-1;i++)
    {
        if(arr[i]==arr[i+1])
        {if(arr[i]==-1)break;
            printf("%d\n",arr[i]);
            i++;
        }
    }
    return 0;
}
//nominal sort function
void sort(int* a,int size)
{int aux[size];
	int low,high;
	low=0;
	high=size-1;
  //calling actual sort function
	msort(a,aux,low,high);
}
//actual sort function
void msort(int* a,int* aux, int low, int high)
{
	int mid;
	if(high<=low)
	return;
	mid=(low+high)/2;
	msort(a,aux,low,mid);
	msort(a,aux,mid+1,high);
	merge(a,aux,low,mid,high);
}
//merge function
void merge(int* a,int *aux, int low, int mid, int high)
{
	int i,j,k;	//aux[] is auxillary array that stores a temporarily.
  //first storing a into aux
	for(i=low;i<high+1;i++)
	aux[i]=a[i];
  //merge-sorting
	j=low;
	k=mid+1;
	for(i=low;i<=high;i++)
	{
		if(j>mid) a[i]=aux[k++];
		else if(k>high) a[i]=aux[j++];
		else if(aux[j]<=aux[k]) a[i]=aux[j++];
		else if(aux[j]>aux[k]) a[i]=aux[k++];
	}
}
