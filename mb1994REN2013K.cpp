#include<bits/stdc++.h>
using namespace std;
int logg(long long x)
{
    int pow=0;
    
    while(x)
    {
        x>>=1;
        pow++;
    }
    
    return pow;
}
long long mult(long long a, long long b, long long mod)
{
    long long prod=0;
    
    a%=mod;b%=mod;
    while(b)
    {
        if(b&1)
        {
            prod+=a;
            if(prod>=mod)prod%=mod;
        }
        
        a<<=1;
        if(a>=mod)a%=mod;
        
        b>>=1;
    }
    return prod;
}
int main()
{
        int t;
        long long a,b;
        cin>>t;
        while(t--)
        {
                cin>>a>>b;
                int maxpow = 1+logg(b);
                long long cur = a%b;
                bool yes=false;
                for(int i=0;i<=maxpow;i++)
                {
                        if(cur==0)
                        {
                                yes=true;
                                break;
                        }
                        cur=mult(cur,a,b);
                }
                if(yes)
                        puts("Yes");
                else puts("No");
        }
        return 0;
}
