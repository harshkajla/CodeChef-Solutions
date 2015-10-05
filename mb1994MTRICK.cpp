#include<bits/stdc++.h>
using namespace std;
bool tracked[101], ignored[101];
int main()
{
    int t,n,m,k,x;
    scanf("%d",&t);
    
    while(t--)
    {
        memset(ignored,false,sizeof ignored);
        memset(tracked,false,sizeof tracked);
        
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            ignored[x]=true;
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&x);
            tracked[x]=true;
        }
        
        //both tracked and ignored..
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            if(tracked[i] && ignored[i])
                cnt1++;
                
            else if(!tracked[i] && !ignored[i])
                cnt2++;
        }
        printf("%d %d\n",cnt1,cnt2);
    }
    return 0;
}
