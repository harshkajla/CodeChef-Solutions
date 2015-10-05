#include<bits/stdc++.h>
using namespace std;
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
    
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<modpow(7,n,1000000007)<<endl;
    }
    return 0;
}
