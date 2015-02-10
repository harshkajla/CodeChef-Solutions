#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n,k,rem,ans;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        
        if(n<k || k == 1)
        {
            printf("%lld\n",n);
            continue;
        }
    
        
        int pos = 0;
        ans = 0;
        while(n)
        {
            rem = n%k;
            n/=k;
            
            ans += rem;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
