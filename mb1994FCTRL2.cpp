#include<bits/stdc++.h>
using namespace std;
int freq[500];
long long fact[501],invfact[501];
const long long mod=1000000007;
string str;
long long modpow(long long a, long long b, long long mod)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a);
            if(ans>=mod)
                ans%=mod;
        }
        
        a*=a;
        if(a>=mod)a%=mod;
        
        b>>=1;
    }
    return ans;
}
int main()
{
    int t;
    long long ans;
    
    //pre-calculate fact mods..
    fact[0]=1;
    for(int i=1;i<=500;i++)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)
            fact[i]%=mod;
            
        invfact[i]=modpow(fact[i], mod-2, mod);
    }
    
    cin>>t;
    
    while(t--)
    {
        memset(freq, 0, sizeof freq);
        
        cin>>str;
        for(int i=0;str[i];i++)
            freq[str[i]]++;
            
        ans=fact[str.size()];
        for(int i=0;i<500;i++)
        {
            if(freq[i])
            {
                ans=(ans*invfact[freq[i]]);
                if(ans>=mod)
                    ans%=mod;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
