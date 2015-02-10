#include<bits/stdc++.h>
#define lol long long
using namespace std;
 
const lol m = 1000000007;
lol modpow(lol a, lol b, lol mod)
{
    if(b == 0)
        return 1;
        
    lol ans = 1;
    while(b)
    {
        if(b&1)
            ans = (ans*a)%mod;
            
        a = (a*a)%mod;
        b>>=1;
    }
    
    return ans;
}
 
int main()
{
    int t;
    lol k,n;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%lld%lld",&k,&n);
        
        if(n == 1)
            printf("1\n");
            
        else if(n == 2 || n == 3)
            printf("%lld\n",k%m);
            
        else 
        {
            lol ans1 = modpow(2,n-3,m-1);
            lol ans2 = modpow(k, ans1, m);
            
            printf("%lld\n",ans2);
        }
    }
    
    return 0;
}
