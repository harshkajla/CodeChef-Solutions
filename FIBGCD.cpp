#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long fib[1000001];
int main()
{
    int t,a,b;
    
    //precomputation.
    fib[0]=0;
    fib[1]=1;
    for(int i = 2;i<=1000000;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] > mod)
        fib[i] %= mod;
    }
    
    scanf("%d",&t);
    
    while(t--)
    {   
        scanf("%d%d",&a,&b);
        
        int g = __gcd(a,b);
        
        printf("%lld\n",fib[g]);
    }
    
    return 0;
}
