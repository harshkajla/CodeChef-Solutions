#include<bits/stdc++.h>
using namespace std;
char str[100005];
int cur[100010];
int main()
{
    int t,n,k,ans;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&n,&k);
        scanf("%s",str);
        
        ans=0;
        for(int i=0;i<=n;i++)
            cur[i]=0;
        
        int state=0;
        for(int i=0;str[i];i++)
        {
            if(cur[i])
                state=1-state;
                
            if((state==0 && str[i]=='R') || (state==1 && str[i]=='G'))
            {
                ++ans;
                state=1-state;
                cur[min(n,i+k)]=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
