#include<stdio.h>
#define lol long long
const lol mod=1000003;
lol fact[1000006];
inline lol modpow(lol a, lol b, lol mod)
{
    lol prod=1;
    if(a>=mod)a%=mod;
    if(b>=mod)b%=mod;
    while(b)
    {
        if(b&1)
        {
            prod=(prod*a);
            if(prod>=mod)
                prod%=mod;
        }
            
        a=(a*a);
        if(a>=mod)
            a%=mod;
        b>>=1;
    }
    
    return prod;
}
lol ncr(lol n, lol r)
{
    if(n>=mod)
        return 0;
        
    lol a=fact[n];
    lol b=modpow(fact[r],mod-2,mod);
    lol c=modpow(fact[n-r],mod-2,mod);
    
    a=(a*b)%mod;
    a=(a*c)%mod;
    
    return a;
}
lol Lucas(lol n, lol m, lol p)
{
    if (n==0 && m==0) return 1;
    int ni = n % p;
    int mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * ncr(ni, mi);
}
int main()
{
    lol t,n,l,r,m,top,bottom,rem,first,last,m1,m2,prod;
    lol ans,temp,i;
    
    //precompute the factorials..
    fact[0]=1;
    for(i=1;i<mod;i++)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)
            fact[i]%=mod;
    }
    
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&l,&r);
        
        m=r-l+1;
        
        if((m+n)<=mod)
        {
            //puts("first");
            ans=ncr(m+n,n)-1;
        }
        
        else
        {
            //puts("second");
            top=m+n;
            bottom=m<n?m:n;
            
            ans=Lucas(top,bottom,mod)-1;
        }
        
        while(ans<0)ans+=mod;
        if(ans>=mod)ans%=mod;
        
        printf("%lld\n",ans);
    }
    return 0;
}
