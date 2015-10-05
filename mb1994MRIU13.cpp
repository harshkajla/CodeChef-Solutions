#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,n,k,ans,p,c;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d%d%d",&x,&y,&k,&n);
        
        ans=0;
        x-=y;
        
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p,&c);
            if(p>=x && c<=k)
            {
                ans=1;
            }
        }
        
        puts(ans?"LuckyChef":"UnluckyChef");
    }
    
    return 0;
}
