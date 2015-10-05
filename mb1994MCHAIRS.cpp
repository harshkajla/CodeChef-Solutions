#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    int t,n,f;
    lol ans;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            puts("1");
            continue;
        }
        
        f=0;ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                f=(i!=1);
                ans+=i;
                if((i*i)!=n)
                    ans+=n/i;
            }
        }
        if(f==0)
            cout<<n+1<<endl;
        else
            cout<<ans<<endl;
    }
}
