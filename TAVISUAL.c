#include<stdio.h>
int main()
{
    int t,i,q,n,c,initial,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&c,&q);
        initial=c;
        for(i=0;i<q;i++)
        {
            scanf("%d%d",&l,&r);
            if(initial>=l && initial<=r)
            {
                initial=l+r-initial;
            }
        }
        printf("%d\n",initial);
    }
    return 0;
}
