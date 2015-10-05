#include<stdio.h>
#include<string.h>
void quickSort( int[], int, int);
int partition( int[], int, int);
int main()
{
    int t,temp,i,size,count,len,j;
    scanf("%d",&t);
    char str[1001];
    int val[1001];
    while(t--)
    {
        scanf("%s",str);
        //sorting str
        len=strlen(str);
        i=0;
        while(str[i]!='\0')
        {
            val[i]=(int)str[i];
            i++;
        }
    quickSort(val,0,i-1);
    size=i;
    
    //traversing for odd
    temp=val[0];count=0;
    for(i=0;i<size;i++)
    {
        if(val[i]==temp)count++;
        else
        {
            if(count%2==1)
                for(j=0;j<count;j++)printf("%c",temp);
            temp=val[i];count=1;
        }
    }if(count%2==1)for(j=0;j<count;j++)printf("%c",temp);
     count=0;temp=val[0];
     for(i=0;i<size;i++)
    {
        if(val[i]==temp)count++;
        else
        {
            if(count%2==0)
                for(j=0;j<count;j++)printf("%c",temp);
            temp=val[i];count=1;
        }
    }if(count%2==0)for(j=0;j<count;j++)printf("%c",temp);
    printf("\n");
    }return 0;
}
void quickSort( int a[], int l, int r)
{
   int j;
   if( l < r )
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
}
int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}
