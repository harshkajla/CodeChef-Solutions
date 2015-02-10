#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;
ll findlow(ll q, ll n)
{
    ll l=1,r=n,ans=0,mid,tmp;
    while(l<=r)
    {
        mid=(l+r)>>1;
        tmp=q-mid;
        if(tmp>=n+1 && tmp<=n*2)
        {
            ans=mid;
            r=mid-1;
        }
        else if(tmp<=n)
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
ll findhigh(ll q, ll n)
{
    ll l=1,r=n,ans=0,mid,tmp;
    while(l<=r)
    {
        mid=(l+r)>>1;
        tmp=q-mid;
        if(tmp>=n+1 && tmp<=n*2)
        {
            ans=mid;
            l=mid+1;
        }
        else if(tmp<=n)
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    long long n,m,q,l,r;
    scanf("%lld%lld",&n,&m);
    while(m--)
    {
        scanf("%lld",&q);
        l=findlow(q,n);
        r=findhigh(q,n);
        //printf("l=%lld r=%lld\n",l,r);
        if(l==0 && r==0)
            printf("0\n");
        else
        printf("%lld\n",r-l+1);
    }
    return 0;
}
