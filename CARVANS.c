#include<stdio.h>
int main()
{
    int t,n,maxspeeds,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        scanf("%d",&a[0]);
        maxspeeds=1;
        for(i=1;i<n;i++)
        {
           scanf("%d",&a[i]);
           if(a[i]<=a[i-1])maxspeeds++;
           else a[i]=a[i-1];
        }
        printf("%d\n",maxspeeds);
    }
    return 0;
}
