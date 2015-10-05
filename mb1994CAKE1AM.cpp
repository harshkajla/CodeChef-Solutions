#include<bits/stdc++.h>
using namespace std;
int a[100001];
const long long mod = 1000000007;
long long modpow(long long a, long long b, long long mod)
{
    long long prod=1ll;
    
    a%=mod;b%=mod;
    
    while(b)
    {
        if(b&1)
        {
            prod*=a;
            if(prod>=mod)prod%=mod;
        }
        
        a*=a;
        if(a>=mod)a%=mod;
        
        b>>=1;
    }
    
    return prod;
}
int main()
{
    int t,n,x;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        sort(a,a+n);
        
        long long maxsum = 0, minsum = 0;
        
        for(int i=0;i<n;i++)
        {
            maxsum += modpow(2,i,mod)*a[i];
            minsum += modpow(2,n-1-i,mod)*a[i];
            
            if(maxsum >= mod)
            maxsum%=mod;
            
            if(minsum >= mod)
            minsum %= mod;
        }
        
        maxsum -= minsum;
        
        while(maxsum<0)maxsum+=mod;
        
        cout<<maxsum<<endl;
    }
}
