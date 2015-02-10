#include<stdio.h>
void sort(int*, int);
void msort(int*, int, int,int*);
void merge(int*, int, int, int,int*);
int main()
{
    int t,size,i;
    scanf("%d",&t);size=t;
    int a[t];
    for(i=0;i<t;i++)
    {
        scanf("%d",&a[i]);
    }
sort(a,t);
        for(i=0;i<t;i++)
        {
                printf("%d\n",a[i]);
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
                if(j>mid) a[i]=aux[k++];
                else if(k>high) a[i]=aux[j++];
                else if(aux[j]<=aux[k]) a[i]=aux[j++];
                else if(aux[j]>aux[k]) a[i]=aux[k++];
        }
}
