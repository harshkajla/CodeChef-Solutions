#include<stdio.h>
int main()
{
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",n+n*(n+1)/2);
    }
}
