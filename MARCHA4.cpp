#include<stdio.h>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;
ll modpow(ll a, int mod)
{
    ll b=a,ans=1;
    a%=mod;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int nod(ll x)
{
    if(x==0)return 1;
    int c=0;
    while(x)
    {
        x/=10;c++;
    }
    return c;
}
int main()
{
    int t,k;
    long long lastk,n,firstk;
    long double power,x;
    int pows[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&n,&k);
        x=n*log10l(n);
        x-=(int)x;
        //last k digits..
        lastk=modpow(n,pows[k]);
        firstk=(ll)pow(10,x+k-1);
        printf("%lld ",firstk);
        for(int i=nod(lastk);i<k;i++)
            putchar('0');
        printf("%lld\n",lastk);
    }
    return 0;
}
