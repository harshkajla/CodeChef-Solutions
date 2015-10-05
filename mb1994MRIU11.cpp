#include<bits/stdc++.h>
#define lol long long
using namespace std;
 
lol fact[10000001];
lol m;
 
inline lol mult(lol a, lol b)
{
    a%=m;b%=m;
    
    lol ans=0;
    while(b)
    {
        if(b%2==1)
            ans=(ans+a)%m;
            
        b>>=1;
        a<<=1;
    }
    
    return ans;
}
inline lol findsum(lol p)
{
    lol temp;
    
    if(p%2==0)
    {
        temp = mult(p>>1,p+1);
    }
    
    else
    {
        temp = mult((p+1)>>1, p);
    }
    
    if(temp>=m)
        temp%=m;
        
    temp = mult(temp,p);
    
    if(temp>=m)
        temp%=m;
        
    return temp;
}
 
int main()
{
    lol n;
    lol p;
    
    scanf("%lld%lld",&n,&m);
    
    fact[1] = 1;
    for(int i = 2; i < m; i++)
    {
        fact[i] = fact[i-1] * static_cast<lol>(i);
        
        if(fact[i]>=m)
            fact[i] %= m;
    }
    
    lol ans = 0, temp;
    
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&p);
        
        temp = findsum(p);
        
        if(temp>=m)
            temp%=m;
            
        if(p <= m-2)
        {
            temp += fact[static_cast<int>(p+1)];
            if(temp>=m)
                temp %= m;
        }
        
        ans += temp;
        
        if(ans >= m)
            ans %= m;
    }
 
    ans -= n;
    while(ans<0ll)
        ans+=m;
    
    printf("%lld\n",ans%m);
    return 0;
}
