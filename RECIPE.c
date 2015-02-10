#include<stdio.h>
int main()
{
    int t,n,i,newGcd,a[50];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&a[0]);
        newGcd=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            newGcd=gcd(newGcd,a[i]);
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]/newGcd);
        }
        printf("\n");
    }
    return 0;
}
int gcd(int a, int b)
{
    if(a==b)return a;
    if(a==0)return b;
    if(b==0)return a;
    if(a>b)return gcd(a%b,b);
    else return gcd(b%a,a);
}
