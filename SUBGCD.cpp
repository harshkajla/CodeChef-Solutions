#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,temp,gcd;
    scanf("%d",&t);
    while(t--)
    {
        gcd=-1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(gcd==-1)gcd=temp;
            else gcd=__gcd(gcd,temp);
        }
        if(gcd==1)
            printf("%d\n",n);
        else puts("-1");
    }
    return 0;
}
