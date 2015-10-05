#include<bits/stdc++.h>
#define mp make_pair
#define lol long long
using namespace std;
int main()
{
    int t,n;
    lol x,mini,sum;
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mini=LONG_LONG_MAX;
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(x<mini)
                mini=x;
            sum+=x;
        }
        printf("%lld\n",mini*(sum-mini));
    }
    
    return 0;
}
