#include<bits/stdc++.h>
using namespace std;
long long a[50001];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            s+=a[i];
        }
        s/=static_cast<long long>(n-1);
        
        for(int i=0;i<n;i++)
        {
            printf("%lld ",s-a[i]);
        }
        puts("");
    }
    return 0;
}
