#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef long long int ll;
inline ll c(ll n, ll r)
{
    long double ans;
    if(r>n/2)r=n-r;
    if(n==r||r==0)return 1;
    else if(r==1|| r==n-1)return n;
    ans=1.0;
    while(r!=0)
    {
        ans=ans*(n-r+1.0)/(r+0.0);
        r--;
    }
    return llrintl(ans);
}
int main()
{
    ll n,r;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&r);
        if(n==1)printf("1\n");
        else
        printf("%lld\n",c(n-1,r-1));
    }
    return 0;
}
