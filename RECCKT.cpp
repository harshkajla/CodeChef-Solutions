#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    int t,n;
    lol x,ans,mini,maxi;
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        
        scanf("%lld",&x);
        maxi=mini=x;
        ans=INT_MIN;
        for(int i=1;i<n;i++)
        {
            scanf("%lld",&x);
            
            lol d1 = x-maxi;
            lol d2 = x-mini;
            
            //printf("d1=%lld d2=%lld maxi=%lld mini=%lld\n",d1,d2,maxi,mini);
            if(x>maxi)
                maxi=x;
            else if(x<mini)
                mini=x;
                
            ans=max(ans,max(d1,d2));
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
