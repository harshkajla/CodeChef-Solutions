#include<stdio.h>
#include<math.h>
int main()
{
unsigned long long int sum=0,x,n,sum1=0;
    int i;
    scanf("%llu",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%llu",&x);
        sum+=x;
        sum1+=i;
    }
    if(sum1==sum)
    printf("YES\n");
    else printf("NO\n");
    return 0;
}
