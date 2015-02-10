#include<stdio.h>
int main()
{
    int t,i,a,n;
    long int sum,c;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%ld",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        if(c>=sum)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
