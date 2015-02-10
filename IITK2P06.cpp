#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,e,o,re,ro,ans,sum;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&e,&o);
        
        if((e+o)%5!=0)
        {
            puts("-1");
            continue;
        }
        
        sum = e+o;
        
        re = sum/5;
        re*=2;
        
        ro = sum/5;
        ro*=3;
        
        if(e>re)
            ans=e-re;
            
        else if(o>ro)
            ans=o-ro;
        
        else ans=0;
        printf("%d\n",ans);
    }
    
    return 0;
}
