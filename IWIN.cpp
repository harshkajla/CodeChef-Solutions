#include<stdio.h>
int bits(int ans)
{
    int cnt=0;
    while(ans)
    {
        cnt+=(ans&1);
        ans>>=1;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int ans=0,x;
        for(int i=0;i<15;i++)
        {
            scanf("%d",&x);
            ans^=x;
        }
        
        scanf("%d",&x);
        if(bits(ans)>x)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
