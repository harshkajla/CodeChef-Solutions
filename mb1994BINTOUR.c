#include<stdio.h>
int main()
{
    int t,s,n,c,extraCatalysts;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&s,&n,&c);
        if(n>=s)
        {
            printf("YES 0\n");
            continue;
        }
        extraCatalysts=ceil((float)(s-n)/2.0);
        if(extraCatalysts<=c)
        {printf("YES %d\n",extraCatalysts);continue;}
        else
        {printf("NO\n");continue;}
    }
    return 0;
}
