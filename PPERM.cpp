#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
bool notprime[5000001];
long long primes[5000001];
long long ans[5000001];
void sieve()
{
    notprime[0]=notprime[1]=true;
    for(int i=2;i<=2235;i++)
    {
        if(!notprime[i])
        {
            for(int j=i*i;j<=5000000;j+=i)
                notprime[j]=true;
        }
    }
    primes[0]=0;ans[0]=1;
    for(int i=1;i<=5000000;i++)
    {
        primes[i]=primes[i-1]+(notprime[i]?0:1);
        ans[i]=ans[i-1]*(1+primes[i]);
        if(ans[i]>mod)
            ans[i]%=mod;
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    sieve();
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
