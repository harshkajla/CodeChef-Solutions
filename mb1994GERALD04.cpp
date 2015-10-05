#include<bits/stdc++.h>
const long long mod=1000000007;
using namespace std;
long long fact[1000001];
long long modpow(long long a, long long b, long long mod)
{
    long long ans=1ll;
    while(b)
    {
        if(b&1)
            ans=(ans*a);
        if(ans>=mod)ans%=mod;
        a=(a*a);
        if(a>=mod)a%=mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    int t;
    long long n;
    
    fact[0]=1;
    
    for(int i=1;i<=1000000;i++)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)fact[i]%=mod;
    }
    
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<6)
        {
            puts("FIGHT");
            continue;
        }
        
        long long ans=fact[n-1];
        ans*=modpow(fact[n-6],mod-2,mod);
        ans%=mod;
        ans*=modpow(fact[5],mod-2,mod);
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}
