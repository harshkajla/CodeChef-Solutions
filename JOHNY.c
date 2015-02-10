#include<stdio.h>
void sort(int*, int);
void msort(int*, int, int,int*);
void merge(int*, int, int, int,int*);
int bsearch(int* a, int val,int size);
int main()
{
    int t,i,n,val,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        val=a[k-1];
        sort(a,n);
        //performing binary search
        printf("%d\n",bsearch(a,val,n));
    }
    return 0;
}
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
int bsearch(int* a, int val,int size)
{
    int min=0,max=size-1,mid;
    while(min<=max)
    {
        mid=(min+max)/2;
        if(a[mid]==val)return (mid+1);
        else if(a[mid]>val)
        {
            max=mid-1;
        }
        else if(a[mid]<val)
        {
            min=mid+1;
        }
    }
}
