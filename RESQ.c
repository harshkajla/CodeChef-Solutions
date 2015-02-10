#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        for(i=sqrt(n);i>=1;i--)
        {
            if(n%i==0)
            {
                printf("%d\n",n/i-i);
                break;
            }
        }
    }
    return 0;
}
