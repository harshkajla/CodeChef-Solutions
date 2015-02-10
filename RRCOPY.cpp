#include<stdio.h>
int hash[100001];
int main()
{
    int t,i,x,n,ans;
    scanf("%d",&t);
    while(t--)
    {scanf("%d",&n);
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(hash[x]!=t+1){ans++;hash[x]=t+1;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
